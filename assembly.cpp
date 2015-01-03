#include "assembly.h"

Value* NUMCG(Expnode* node, CodeContext& context){
	int v = node->integer;
	return ConstantInt::get(Type::getInt32Ty(getGlobalContext()),v, true);
}
Value* getArrayPtr(Node* node,IRBuilder<>* builder)
{
	vector<Node*> vec;//index from node
	vector<Value*> idx;//convert it to Value*
	Arrnode* nd=(Arrnode*)node;
	/* Begin:Just Follow It */
	nd->getIndices(vec);
	idx.push_back(ConstantInt::get(Type::getInt32Ty(getGlobalContext()),0,true));
	for(int i=vec.size()-1;i>=0;i--)
	{
		fprintf(stderr,"[%x-%x]",vec[i],((Varnode*)vec[i])->value);
		idx.push_back(((Varnode*)vec[i])->value);
	}
	/* End: Don't ask why*/
	fprintf(stderr,"ARR:sym:%x\n",nd->sym);
	return builder->CreateGEP(nd->sym->value,idx);
}		
Value* assignmentCG(Expnode* node, CodeContext& context){
	vector<Node*> zip;                                            
	unrolling(node, zip);
	Value* Val = ((Expnode*)zip[2])->value;
	Value* Ptr;
	IRBuilder<>* builder=context.getBuilder();
	if(zip[0]->type==Expnode::ARR)
	{
		//if it is an array
		Ptr=getArrayPtr(zip[0],builder);
		return builder->CreateStore(Val,Ptr);

	}
	else
	{
		Varnode* nd=((Varnode*)zip[0]);
		Ptr=nd->value;
		fprintf(stderr,"Val:%x,ptr:%x",Val,Ptr);
		return builder->CreateStore(Val, Ptr); 
	}
}
Value* varCG(Expnode* node,CodeContext& context)
{
	Value* Ptr;
	IRBuilder<>* builder=context.getBuilder();
	if(strcmp(node->first->name,"var")==0)
	{
		//array
		if(node->type=Expnode::ARR)
		{
			Ptr=getArrayPtr(node,builder);
			return builder->CreateLoad(Ptr,((Varnode*)node)->sym->name);
		}
		else//class
		{

		}
	}
	else
	{
		fprintf(stderr,"node:%x:%d-%s-symbol:%x\n",node,node->type,node->name,((Varnode*)node)->sym);
		SYMBOL *s=((Varnode*)node)->sym;
		return new LoadInst(s->value,"_"+s->name,context.currentBlock());		

	}
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
				FunctionType *ftype;
				vector<Type*> argtypes;
				symfunc* f=static_cast<symfunc*>(s);
				for(int j=0;j<f->m_parameter.size();j++)
				{
					argtypes.push_back(t_type[f->m_parameter[j]->type]);
				}				
				if(s->type==-1)//-1:void
					ftype=FunctionType::get(Type::getVoidTy(getGlobalContext()),false);
				else
					ftype=FunctionType::get(t_type[s->type],makeArrayRef(argtypes),false);
				Function *func=Function::Create(ftype,GlobalValue::InternalLinkage,s->name,this->module);
				BasicBlock *bblock=BasicBlock::Create(getGlobalContext(),s->name,func);
				this->pushBlock(bblock);
				initDeclar(f);
				((Expnode*)f->code)->codeGen(*this);
				this->popBlock();
				continue;
			}
			ConstantInt* con=ConstantInt::get(Type::getInt32Ty(getGlobalContext()),s->size,false);
			s->value=new AllocaInst(t_type[s->type],con,s->name,currentBlock());
			fprintf(stderr,"%s-symobol:%x\n",s->name.c_str(),s->value);
			local[s->name]=s->value;
		}
	}
	fprintf(stderr,"parent:%x\n",base->parent);
	//	if(base->parent)
	//		initDeclar(base->parent);
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
			t_type.push_back(StructType::get(getGlobalContext()));
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
