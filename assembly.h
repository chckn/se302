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


struct IterateBlocks {
  llvm::BasicBlock *CondBB;
  llvm::BasicBlock *BodyBB;
  llvm::BasicBlock *BodyEndBB;
  llvm::BasicBlock *EndBB;
  IterateBlocks(llvm::BasicBlock *condBB = 0, llvm::BasicBlock *bodyBB = 0, 
                llvm::BasicBlock *bodyEndBB = 0, llvm::BasicBlock *endBB = 0){}
};


class CodeGenBlock {
public:
    BasicBlock *block;
    Value *returnValue;
	IRBuilder<> *builder;
    std::map<std::string, Value*> locals;
};

class CodeContext {
    std::stack<CodeGenBlock *> blocks;
    vector<Type*> t_type;
	Function *mainFunction;
	void initDeclar(symbase*);
   //std::map<std::string, llvm::AllocaInst*> Variables;
  //EnvStack<llvm::AllocaInst*> TheEnvStack;
  
  // The iteration statement stack.
  //std::stack<IterateBlocks*> IterateStmtStack;
public:
	std::stack<IterateBlocks*> IterateStmtStack;
    //EnvStack<llvm::AllocaInst*> TheEnvStack;
    Module *module;
    CodeContext() { module = new Module("main", getGlobalContext()); }
    
	void generate(symprog*);
    std::map<std::string, Value*>& locals() { return blocks.top()->locals; }
    BasicBlock *currentBlock() { return blocks.top()->block; }
	IRBuilder<> *getBuilder() { return blocks.top()->builder;}
    void pushBlock(BasicBlock *block) { blocks.push(new CodeGenBlock()); blocks.top()->returnValue = NULL; blocks.top()->block = block; blocks.top()->builder=new IRBuilder<>(block); }
    void popBlock() { CodeGenBlock *top = blocks.top(); blocks.pop(); delete top; }
    void setCurrentReturnValue(Value *value) { blocks.top()->returnValue = value; }
    Value* getCurrentReturnValue() { return blocks.top()->returnValue; }
};

void assmebly();
