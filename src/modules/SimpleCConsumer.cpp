#include "clang/AST/ASTConsumer.h"
#include "clang/AST/ASTContext.h"
#include "clang/Rewrite/Core/Rewriter.h"

class SimpleCConsumer : public clang::ASTConsumer {
public:
    explicit SimpleCConsumer(clang::Rewriter &R) : TheRewriter(R) {}

    void HandleTranslationUnit(clang::ASTContext &Context) override {  
        llvm::outs() << "AST is ready for processing.\n";
    }
    private:
    clang::Rewriter &TheRewriter;
};

