#ifndef SIMPLECCONSUMER_H
#define SIMPLECCONSUMER_H

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/ASTContext.h"
#include "clang/Rewrite/Core/Rewriter.h"

class SimpleCConsumer : public clang::ASTConsumer {
public:
    // Constructor declaration
    explicit SimpleCConsumer(clang::Rewriter &R);

    // Overridden method declaration
    void HandleTranslationUnit(clang::ASTContext &Context) override;

private:
    clang::Rewriter &TheRewriter;
};

#endif // SIMPLECCONSUMER_H