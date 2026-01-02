#ifndef SIMPLE_C_CONSUMER_H
#define SIMPLE_C_CONSUMER_H

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/ASTContext.h"
#include "clang/Rewrite/Core/Rewriter.h"

class SimpleCConsumer : public clang::ASTConsumer {
public:
    explicit SimpleCConsumer(clang::Rewriter &R);

    void HandleTranslationUnit(clang::ASTContext &Context) override;

private:
    clang::Rewriter &TheRewriter;
};

#endif