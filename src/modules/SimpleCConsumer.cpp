#include "clang/AST/ASTConsumer.h"
#include "clang/AST/ASTContext.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "SimpleCConsumer.h"
#include "llvm/Support/raw_ostream.h"

SimpleCConsumer::SimpleCConsumer(clang::Rewriter &R) : TheRewriter(R) {
}

void SimpleCConsumer::HandleTranslationUnit(clang::ASTContext &Context) {
    llvm::errs() << ">>> SimpleC AST Consumer is active and processing.\n";
}

