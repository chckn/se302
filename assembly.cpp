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
//	for(int i=0;i<vec.size();i++)
//	{
//		fprintf(stderr,"[%x-%x]",vec[i],((Varnode*)vec[i])->value);
		idx.push_back(((Varnode*)vec[0])->value);
//	}
	if(nd->first->type==Expnode::VAR)
		nd->ptr=builder->CreateGEP(nd->sym->value,idx);
	else
		nd->ptr=builder->CreateGEP(((Arrnode*)nd->first)->ptr,idx);
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
		Ptr=nd->value;
		fprintf(stderr,"Val:%p,ptr:%p",Val,Ptr);
		return builder->CreateStore(Val, Ptr); 
//	}
}

Value* EXPCG(Expnode* node,CodeContext& context){
	
	return ((Expnode*)(node->first))->value;
}

Value* PRIMARYCG(Expnode* node,CodeContext& context){
	vector<Node*> zip;
        unrolling(node, zip);
	IRBuilder<>* builder=context.getBuilder();
	Value* retval;
	bool flag = false;
	if(strcmp(zip[0]->name,"NUM") == 0){
		retval = ((Expnode*)zip[0])->value;
		flag = true;
	}
	if(strcmp(zip[0]->name,"(") == 0){
		retval = ((Expnode*)zip[1])->value;
		flag = true;
        }
	if(strcmp(zip[0]->name,"var") == 0){
		retval =((Expnode*)zip[0])->value;
		flag = true;
        }
	if(strcmp(zip[0]->name,"fcall") == 0){
		retval = ((Expnode*)zip[0])->value;
		flag = true;
        }
	if (!flag){
		// error!
	}
	return retval;

}

Value* TERMCG(Expnode* node,CodeContext& context){
        vector<Node*> zip;
        unrolling(node, zip);
        IRBuilder<>* builder=context.getBuilder();
	Value* retval;
	Instruction::BinaryOps instr;
	if(strcmp(zip[0]->name,"primary") == 0){
		retval = ((Expnode*)zip[0])->value;
	}
        if(strcmp(zip[0]->name,"term") == 0){
    		Instruction::BinaryOps instr;
		if (strcmp(zip[1]->name,"OP") != 0){
			//error!
		}
		if (strcmp(zip[1]->str,"+") == 0){
			instr = Instruction::Add; 
			goto math;
		}
		if (strcmp(zip[1]->str,"-") == 0){
                	instr = Instruction::Sub; 
			goto math;        
                }
		if (strcmp(zip[1]->str,"*") == 0){
                        instr = Instruction::Mul; 
			goto math;
                }
		if (strcmp(zip[1]->str,"/") == 0){
                	instr = Instruction::SDiv; 
			goto math;        
        	}
	}
math:
    	return BinaryOperator::Create(instr, ((Expnode*)zip[0])->value,
        	((Expnode*)zip[2])->value, "", context.currentBlock()); // not use builder??


}

Value* FINALCG(Expnode* node,CodeContext& context){
        vector<Node*> zip;
        unrolling(node, zip);
        IRBuilder<>* builder=context.getBuilder();
        Value* retval;
	if (symcode::isname(zip[0], "term")){
		retval = ((Expnode*)zip[0])->value;
	}
	if (symcode::isname(zip[0], "final")){
		if (strcmp(zip[1]->str,"+") == 0){
			retval = builder->CreateNSWAdd(((Expnode*)zip[0])->value, ((Expnode*)zip[2])->value);
		}else if (strcmp(zip[1]->str,"-") == 0){
			retval = builder->CreateNSWSub(((Expnode*)zip[0])->value, ((Expnode*)zip[2])->value);
                } else {
			//error
		}
	} else{
		//error
	}
	return retval;

}

Value* BPRIMARYCG(Expnode* node,CodeContext& context)
{
        Value* Ptr;
	vector<Node*> zip;
	unrolling(node, zip);
        IRBuilder<>* builder=context.getBuilder();
	Value* retval;
        if(strcmp(zip[0]->name,"bexpression") == 0){
		retval = ((Expnode*)zip[0])->value;
	}else if (strcmp(zip[1]->name,"coperator") == 0){
		if (symcode::isname(zip[1]->first, "==")){
			retval = builder->CreateICmpEQ(((Expnode*)zip[0])->value,((Expnode*)zip[2])->value);
		}
		if (symcode::isname(zip[1]->first, "less")){
			retval = builder->CreateICmpSLT(((Expnode*)zip[0])->value, ((Expnode*)zip[2])->value);
                }
		if (symcode::isname(zip[1]->first, "large")){
			retval = builder->CreateICmpSGT(((Expnode*)zip[0])->value, ((Expnode*)zip[2])->value);
                }
		if (symcode::isname(zip[1]->first, "less_equal")){
			retval = builder->CreateICmpSLE(((Expnode*)zip[0])->value, ((Expnode*)zip[2])->value);
                }
		if (symcode::isname(zip[1]->first, "large_equal")){
			retval = builder->CreateICmpSGE(((Expnode*)zip[0])->value, ((Expnode*)zip[2])->value);
                }

	}
	return retval;
}

Value* BTERMCG(Expnode* node,CodeContext& context)
{
        Value* Ptr;
        vector<Node*> zip;
        unrolling(node, zip);
        IRBuilder<>* builder=context.getBuilder();
        Value* retval;
	if (zip.size() == 1){
		retval = ((Expnode*)zip[0])->value;
	}else if (zip.size() == 3){
		retval = builder->CreateAnd(((Expnode*)zip[0])->value, ((Expnode*)zip[2])->value);
	} else{
		//error
	}
	return retval;
}

Value* BEXPRESSIONSCG(Expnode* node,CodeContext& context)
{
        Value* Ptr;
        vector<Node*> zip;
        unrolling(node, zip);
        IRBuilder<>* builder=context.getBuilder();
        Value* retval;
        if (zip.size() == 1){
                retval = ((Expnode*)zip[0])->value;
        }else if (zip.size() == 3){
                retval =builder->CreateOr(((Expnode*)zip[0])->value, ((Expnode*)zip[2])->value);
        } else{
                //error
        }
        return retval;
}

Value* IFCG(Expnode* node,CodeContext& context)
{
        vector<Node*> zip;
        unrolling(node, zip);
        IRBuilder<>* builder=context.getBuilder();
        Value* retval;
	//retval = builder->CreateCondBr(zip[2], zip[4], zip[6]);
	return retval;
}




/*Value* ELSECG(Expnode* node,CodeContext& context)
{
        vector<Node*> zip;
        unrolling(node, zip);
        IRBuilder<>* builder=context.getBuilder();
        Value* retval;
	if (symcode::isname(zip[1]->name, "EMPTY")){
		//retval = builder->Create
	}else{
		retval = zip[2]->value;
	}
	return retval;
}*/
/*Value* ELIFCG(Expnode* node,CodeContext& context)
{
        vector<Node*> zip;
        unrolling(node, zip);
        IRBuilder<>* builder=context.getBuilder();
        Value* retval;
	retval = builder->CreateCondBr(zip[2], zip[4],<<<<<< blank >>>>>>>);
}

Value* ELIFSCG(Expnode* node,CodeContext& context)
{
        vector<Node*> zip;
        unrolling(node, zip);
        IRBuilder<>* builder=context.getBuilder();
        Value* retval;
	if (symcode::isname(zip[1], "EMPTY")){
		//retval = blank;
	} else{
		retval = 
	}
}*/

Value* WHILECG(Expnode* node,CodeContext& context)
{
        vector<Node*> zip;
        unrolling(node, zip);
        IRBuilder<>* builder=context.getBuilder();
        Value* retval;
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
Value* fcallCG(Node* node,CodeContext& context)
{
	IRBuilder<>* builder=context.getBuilder();
	Funcnode* fcall=(Funcnode*)node;
	Expnode* fname=(Expnode*)(fcall->first);
	vector<Value*> para;//parameter
	if(symcode::isname(fname->first,"var"))
	{
		//class member function
		//push the class as the first parameter
	}
	else
	{

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
	if(symcode::isname(this,"primary"))
        {
                this->value = PRIMARYCG(this,context);
                return;
        }
	if(symcode::isname(this,"term"))
        {
                this->value = TERMCG(this,context);
                return;
        }
	if(symcode::isname(this,"final"))
        {
                this->value = FINALCG(this,context);
                return;
        }
	if(symcode::isname(this,"bprimary"))
        {
                this->value = BPRIMARYCG(this,context);
                return;
        }
	if(symcode::isname(this,"bterm"))
        {
                this->value = BTERMCG(this,context);
                return;
        }
	if(symcode::isname(this,"bexpressions"))
        {
                this->value = BEXPRESSIONSCG(this,context);
                return;
        }
	if(symcode::isname(this,"if"))
        {
                this->value = IFCG(this,context);
                return;
        }
	/*if(symcode::isname(this,"else"))
        {
                this->value = ELSECG(this,context);
                return;
        }*/
	if(symcode::isname(this,"while"))
        {
                this->value = WHILECG(this,context);
                return;
        }
	/*if(symcode::isname(this,"repeat"))
        {
                this->value = REPEATCG(this,context);
                return;
        }
	if(symcode::isname(this,"block"))
        {
                this->value = BLOCKCG(this,context);
                return;
        }
	if(symcode::isname(this,"sentence"))
        {
                this->value = SENTENCECG(this,context);
                return;
        }*/

	/*if(symcode::isname(this,"elif"))
        {
                this->value = ELIFCG(this,context);
                return;
        }
	if(symcode::isname(this,"elifs"))
        {
                this->value = ELIFSCG(this,context);
                return;
        }*/





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
				
				ReturnInst::Create(getGlobalContext(), bblock);
				this->popBlock();
				fprintf(stderr,"func(%s):%p",f->name.c_str(),func);
				f->value=func;
				local[f->name]=func;
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
