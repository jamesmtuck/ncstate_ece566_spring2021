// t4.cpp

#include <stdlib.h>
#include <stdio.h>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Verifier.h"

#include "llvm/Bitcode/BitcodeReader.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Support/SystemUtils.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Support/FileSystem.h"

using namespace llvm;

static LLVMContext TheContext;

int main (int argc, char ** argv)
{  
  /* Build global Module, this will be what we output */
  Module *M = new Module("Tutorial4", TheContext);

  IRBuilder<> Builder(TheContext);

  // Create void function type with no arguments
  FunctionType *FunType = FunctionType::get(Builder.getVoidTy(),false);

  Function *F = Function::Create(FunType,GlobalValue::ExternalLinkage, "main", M);

  BasicBlock *entry = BasicBlock::Create(TheContext, "entry", F);
  Builder.SetInsertPoint(entry);

  // ******** Build for-loop here! ********





  // Verify module is correct
  verifyModule(*M, &errs());
  
  // Print module to screen for debugging
  M->print(errs(),nullptr);

 //Write module to file as IR assembly, for reading
 std::error_code EC;
 raw_fd_ostream OS("main.ll",EC,sys::fs::F_None);   
 M->print(OS,nullptr);

 // Alternatively, write it as bitcode
 //WriteBitcodeToFile(*M,OS);

  /* Return an error status if it failed */
  return 0;
}


