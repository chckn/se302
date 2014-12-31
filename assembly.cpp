#include "assembly.h"



Value* Expnode::codeGen(CodeContext& context)
{
	/*
		Exp

	*/
	Value* intValue=ConstantInt::get(Type::getInt64Ty(getGlobalContext()),32,true);
	Value* Var=new AllocaInst(Type::getInt64Ty(getGlobalContext()),"Var1",context.currentBlock());	
	new StoreInst(intValue,Var,context.currentBlock());
}
void CodeContext::generate(Node* root)
{
	vector<Type*> argTypes;
	FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), makeArrayRef(argTypes), false);
	mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "main", module);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", mainFunction, 0);
	pushBlock(bblock);
	Expnode* newroot=new Expnode(root,(Expnode::NDTYPE)root->type);
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
	context.generate(prog->code);
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
