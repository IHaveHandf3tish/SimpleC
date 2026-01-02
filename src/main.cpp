/*
This is the "driver" of the language
here we're gonna:
Parse command-line arguments (input .sc files, output path, compiler flags)

Initialize Clang's CompilerInstance and SourceManager

Set up the Rewriter for code modifications

Instantiate and run each pass in the correct order

Write the final transpiled C code to output

Optionally invoke the C compiler on the result
*/
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "llvm/Support/raw_ostream.h"
#include "SimpleCConsumer.h"

using namespace clang::tooling;
using namespace clang;
using namespace llvm;

static cl::OptionCategory SimpleCToolCategory("SimpleC Transpiler Options");

class SimpleCTranspilerAction : public ASTFrontendAction {
    public:
    std::unique_ptr<ASTConsumer>CreateASTConsumer(CompilerInstance &CI, StringRef file) override {
        TheRewriter.setSourceMgr(CI.getSourceManager(), CI.getLangOpts());
        return std::make_unique<SimpleCConsumer>(TheRewriter);
    }
    void EndSourceFileAction() override {
        SourceManager &SM = TheRewriter.getSourceMgr();
        TheRewriter.getEditBuffer(SM.getMainFileID()).write(llvm::outs());
    }
    private:
    Rewriter TheRewriter;
};


int main(int argc, const char **argv){
    auto ExpectedParser = CommonOptionsParser::create(argc,argv, SimpleCToolCategory);
    if (!ExpectedParser) {
        llvm::errs() <<ExpectedParser.takeError();
        return 1;
    };
    CommonOptionsParser &OptionsParser = ExpectedParser.get();

    ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());
    return Tool.run(newFrontendActionFactory<SimpleCTranspilerAction>().get());
}

