#include "assembly.h"

Value* NUMCG(Expnode* node, CodeContext& context){
	int value = node->integer;
	return ConstantInt::get(Type::getInt32Ty(getGlobalContext()),value, true);
}

Value* assignmentCG(Expnode* node, CodeContext& context){
	vector<Node*> zip;                                            
        unrolling(node, zip);
	Value* Val = ((Expnode*)zip[2])->codeGen(context);
	Value* Ptr = ((Varnode*)zip[0])->codeGen(context); 
	return new StoreInst (Val, Ptr, context.currentBlock()); 
}



Value* Expnode::codeGen(CodeContext& context)
{
	/*
		Exp

	*/
	Value* intValue=ConstantInt::get(Type::getInt64Ty(getGlobalContext()),32,true);
	Value* Var=new AllocaInst(Type::getInt64Ty(getGlobalContext()),"Var1",context.currentBlock());	
	new StoreInst(intValue,Var,context.currentBlock());
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
			local[s->name]=new AllocaInst(t_type[s->type],con,s->name,currentBlock());		
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
