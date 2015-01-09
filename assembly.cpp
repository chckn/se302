#include "assembly.h"

Value* NUMCG(Expnode* node, CodeContext& context){
	int v = node->integer;
	return ConstantInt::get(Type::getInt32Ty(getGlobalContext()),v, true);
}
Value* getStructPtr(Node* node,IRBuilder<>* builder)
{
	Varnode* nd=(Varnode*)(node->first);
	vector<Node*> vec;
	unrolling(node,vec);
	symclass* cls=(symclass*)t_vec[nd->valtype];
	string stridx=vec[2]->str;
	fprintf(stderr,"ndname:%s,%p,getStructPtr:%x,%x",nd->name,nd->sym->value,nd->value);
	return builder->CreateStructGEP(nd->ptr,cls->m_member[stridx]);
	
}
Value* getArrayPtr(Node* node,IRBuilder<>* builder)
{
	vector<Node*> vec;//index from node
	vector<Value*> idx;//convert it to Value*
	Arrnode* nd=(Arrnode*)node;
	/* Begin:Just Follow It */
	nd->getIndices(vec);
	idx.push_back(ConstantInt::get(Type::getInt32Ty(getGlobalContext()),0,true));
	idx.push_back(((Varnode*)vec[0])->value);
	fprintf(stderr,"%s-getArr-%p,sym:%p(val:%p)\n",nd->name,nd,nd->sym,nd->sym->value);
//	if(nd->first->type==Expnode::VAR)
//		nd->ptr=builder->CreateGEP(nd->sym->value,idx);
//	else
		nd->ptr=builder->CreateGEP(((Varnode*)nd->first)->ptr,idx);
	/* End: Don't ask why*/
	return nd->ptr;
}		
Value* assignmentCG(Expnode* node, CodeContext& context){
	vector<Node*> zip;                                            
	unrolling(node, zip);
	Value* Val = ((Expnode*)zip[2])->value;
	Value* Ptr;
	IRBuilder<>* builder=context.getBuilder();
/*	if(zip[0]->type==Expnode::ARR)
	{
		//if it is an array
		Ptr=getArrayPtr(zip[0],builder);
		return builder->CreateStore(Val,Ptr);

	}
	else
	{
*/	
		Varnode* nd=((Varnode*)zip[0]);
		Ptr=nd->ptr;
		fprintf(stderr,"Val:%x,ptr:%x",Val,Ptr);
		return builder->CreateStore(Val, Ptr); 
//	}
}
Value* varCG(Node* node,CodeContext& context)
{
	Varnode* nd=(Varnode*)node;
	IRBuilder<>* builder=context.getBuilder();
	if(strcmp(node->first->name,"var")==0)
	{
		//array
		int mtype=((Varnode*)node->first)->valtype;
		if(t_vec[mtype]->acc==SYMBOL::ARRAY)
		{
			nd->ptr=getArrayPtr(node,builder);
			return builder->CreateLoad(nd->ptr,((Varnode*)node)->sym->name);
		}
		else//class
		{
			nd->ptr=getStructPtr(node,builder);
			return builder->CreateLoad(nd->ptr,((Varnode*)(node->first->next->next)->str));
		}
	}
	else
	{
		SYMBOL *s=((Varnode*)node)->sym;
		fprintf(stderr,"node:%x:%d-%s-symbol:%s,%x\n",node,node->type,node->name,s->name.c_str(),s->value);
		nd->ptr=s->value;
		if(nd->ptr==NULL)
		{
			symclass* cls=context.getfunc()->parent;
			//getClassVar(cls,s->name);
		}		
		return new LoadInst(nd->ptr,"_"+s->name,context.currentBlock());		

	}
}
Value* fcallCG(Node* node,CodeContext& context)
{
	IRBuilder<>* builder=context.getBuilder();
	Funcnode* fcall=(Funcnode*)node;
	Expnode* fname=(Expnode*)(fcall->first);
	vector<Value*> para;//parameter
	if(symcode::isname(fname->first,"var"))
	{
		para.push_back(((Varnode*)fname->first)->ptr);
		//class member function
		//push the class as the first parameter
	}
		
	Node* i=fcall->last->first;//nevalues
	if(symcode::isname(i,"EMPTY"))
		return	builder->CreateCall(fcall->sym->value,fcall->sym->name);
	vector<Node*> childs;
	unrolling(i,childs);
	while(childs.size()>1)
	{
		para.push_back(((Expnode*)childs[0])->value);
		i=childs[2];
		unrolling(i,childs);
	}	
	para.push_back(((Expnode*)childs[0])->value);
	fprintf(stderr,"\tpara(%s(%p)):%p\n",i->last->name,i->last->first,((Expnode*)i->last)->value);
	fprintf(stderr,"fcall:%p",fcall->sym->value);
	return builder->CreateCall(fcall->sym->value,makeArrayRef(para),fcall->sym->name);
	
}
void returnCG(Node* node,CodeContext& context)
{
	IRBuilder<>* builder=context.getBuilder();
	if(!symcode::isname(node->first,"EMPTY"))
		builder->CreateRet(((Expnode*)(node->first->next))->value);
	else
		builder->CreateRetVoid();
}
void Expnode::codeGen(CodeContext& context,int n=0)
{
	/*
	   Exp
	   Value* intValue=ConstantInt::get(Type::getInt64Ty(getGlobalContext()),32,true);
	   Value* Var=new AllocaInst(Type::getInt64Ty(getGlobalContext()),"Var1",context.currentBlock());	
	   new StoreInst(intValue,Var,context.currentBlock());
	 */

	for(int i=0;i<n;i++)
		fprintf(stderr," ");
	fprintf(stderr,"Node Name:%s,%x\n",this->name,this);
	if(first && strcmp(first->name,"EMPTY")!=0)
		((Expnode*)first)->codeGen(context,n+1);
	if(next && strcmp(next->name,"EMPTY")!=0)
		((Expnode*)next)->codeGen(context,n);
	if(symcode::isname(this,"NUM"))
	{
		this->value=NUMCG(this,context);
		fprintf(stderr," Value:%x\n",this->value);
		return;
	}
	if(symcode::isname(this,"var"))
	{
		this->value=varCG(this,context);
		fprintf(stderr," Value:%x\n",this->value);
		return;
	}	
	if(symcode::isname(this,"assignment"))
	{
		this->value=assignmentCG(this,context);
		fprintf(stderr," Value:%x\n",this->value);
		return;
	}
	if(symcode::isname(this,"fcall"))
	{
		this->value=fcallCG(this,context);
		return;
	}
	if(symcode::isname(this,"return"))
	{
		returnCG(this,context);
		return;
	}

}
void CodeContext::initFunc(symfunc* f,bool par)
{
	FunctionType *ftype;
	vector<Type*> argtypes;
	fprintf(stderr,"func:%s,%s,%d,%p\n",f->name.c_str(),f->parent->name.c_str(),f->parent->type,t_type[f->parent->type]);	
	string f_name=f->parent->name+"."+f->name;
	if(par)
		argtypes.push_back(PointerType::getUnqual(t_type[f->parent->type]));
	for(int j=0;j<f->m_parameter.size();j++)
	{
		argtypes.push_back(t_type[f->m_parameter[j]->type]);
	}				
	if(f->type==-1)//-1:void
		ftype=FunctionType::get(Type::getVoidTy(getGlobalContext()),false);
	else
		ftype=FunctionType::get(t_type[f->type],makeArrayRef(argtypes),false);
	Function *func=Function::Create(ftype,GlobalValue::InternalLinkage,f_name,this->module);
	BasicBlock *bblock=BasicBlock::Create(getGlobalContext(),f_name,func);
	this->pushBlock(bblock);
	initDeclar(f);
	setfunc(f);
	((Expnode*)f->code)->codeGen(*this);	
	ReturnInst::Create(getGlobalContext(), bblock);
	this->popBlock();
	f->value=func;
}
void CodeContext::initDeclar(symbase* base)
{
	map<string,Value*> local=this->locals();
	SYMBOL* s=NULL;
	int size=1;
	for(auto it=base->m_var.begin();it!=base->m_var.end();++it)
	{
		s=it->second;
		if(local.find(s->name)==local.end())
		{
		if(s->acc==SYMBOL::FUNC)
		{ 
			//FUNCTION?
			fprintf(stderr,"Name:%s\n",s->name.c_str());
			initFunc((symfunc*)s,false);
			continue;
		}
		ConstantInt* con=ConstantInt::get(Type::getInt32Ty(getGlobalContext()),s->size,false);
		Value* val=new AllocaInst(t_type[s->type],con,s->name,currentBlock());
		s->value=val;
		fprintf(stderr,"%s:%p-acc:%d,type:%d,size:%d\n",s->name.c_str(),s,s->acc,s->type,s->size);
			local[s->name]=s->value;
		}
	}
	fprintf(stderr,"parent:%x\n",base->parent);
	//	if(base->parent)
	//		initDeclar(base->parent);
}
void CodeContext::genClassFunc(symclass *cls)
{
	SYMBOL* s;
	for(auto it=cls->m_var.begin();it!=cls->m_var.end();++it)
	{
		s=it->second;
		if(s->acc==SYMBOL::FUNC)
		{
			fprintf(stderr,"Func name:%s\n",s->name.c_str());
			initFunc((symfunc*)s);
		}	
	}	
	
}
StructType* CodeContext::genClass(symclass* cls)
{
	fprintf(stderr,"class:%s\n",cls->name.c_str());
	vector<Type*> membertype;
	SYMBOL* s;	
	for(auto it=cls->m_var.begin();it!=cls->m_var.end();++it)
	{
		s=it->second;
		if(s->acc!=SYMBOL::FUNC)
		{
			cls->m_member[s->name]=membertype.size();
			fprintf(stderr,"\tmember:%s-%d\n",s->name.c_str(),cls->m_member[s->name]);
			membertype.push_back(t_type[s->type]);
		}
	}	
	return StructType::create(getGlobalContext(),makeArrayRef(membertype),cls->name);

}
void CodeContext::generate(symprog* prog)
{
	Node *root=prog->code;
	vector<Type*> argTypes;

	//convert t_vec/t_tbl types to Type*
	t_type.clear();
	t_type.push_back(Type::getInt32Ty(getGlobalContext()));
	t_type.push_back(Type::getInt1Ty(getGlobalContext()));
	for(int i=2;i<t_vec.size();i++)
	{
		if(t_vec[i]->acc==SYMBOL::ARRAY)
		{
			t_type.push_back(ArrayType::get(t_type[t_vec[i]->type],t_vec[i]->size));	
		}
		else if(t_vec[i]->acc==SYMBOL::CLASS)
		{
			//structed type
			StructType* t_struct=genClass((symclass*)t_vec[i]);
			t_type.push_back(t_struct);
			genClassFunc((symclass*)t_vec[i]);
		}
	}


	FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), makeArrayRef(argTypes), false);
	mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "main", module);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "program", mainFunction, 0);
	pushBlock(bblock);
	Expnode* newroot=new Expnode(root,(Expnode::NDTYPE)root->type);
	initDeclar(prog);
	newroot->codeGen(*this);
	ReturnInst::Create(getGlobalContext(), bblock);
	popBlock();
}
void assembly()
{
	symprog* prog=semantic(0);
	//Here comes the code	
	//prog->code and any (symfunc*)->code is the root of tree(I have change the name)
	CodeContext context;
	context.generate(prog);
	//	ofstream ouf("aout.txt");
	//	context.module->print(cout);
	context.module->dump();	

}
int main()
{
	//DO NOT add code at this place
	assembly();
	return 0;
}
