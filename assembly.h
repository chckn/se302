#include "semantic.h"
#include <cassert>
#include <stack>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRBuilder.h>
using namespace llvm;
void assmebly();
Value* NUMCG(Expnode *node,CodeContext& context);
Value* assignmentCG(Expnode *node,CodeContext& context); 
#include <llvm/Support/raw_ostream.h>
extern vector<SYMBOL*> t_vec;
extern map<string,int> t_tbl;

class CodeGenBlock {
public:
    BasicBlock *block;
    symfunc* function;
	IRBuilder<> *builder;
    std::map<std::string, Value*> locals;
};

class CodeContext {
    std::stack<CodeGenBlock *> blocks;
    vector<Type*> t_type;
	Function *mainFunction;
	void initDeclar(symcode*);
public:
	Function *printFunc;
    Module *module;
    CodeContext() { module = new Module("main", getGlobalContext()); }
	StructType* genClass(symclass*);    
	void genClassFunc(symclass*);
	void initFunc(symfunc*,bool par=true);
	void generate(symprog*);
    std::map<std::string, Value*>& locals() { return blocks.top()->locals; }
    BasicBlock *currentBlock() { return blocks.top()->block; }
	IRBuilder<> *getBuilder() { return blocks.top()->builder;}
    void pushBlock(BasicBlock *block) { blocks.push(new CodeGenBlock()); blocks.top()->function = NULL; blocks.top()->block = block; blocks.top()->builder=new IRBuilder<>(block); }
    void popBlock() { CodeGenBlock *top = blocks.top(); blocks.pop(); delete top; }
    void setfunc(symfunc* f) { blocks.top()->function = f; }
    symfunc* getfunc() { return blocks.top()->function; }
};

void assmebly();
