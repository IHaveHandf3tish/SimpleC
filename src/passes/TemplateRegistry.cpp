#include "clang/AST/ASTContext.h"
#include "clang/AST/DeclTemplate.h"
#include "clang/Lex/Lexer.h"
#include <map>
#include <string>

using namespace clang;

struct TemplateBlueprint {
    std::string sourceCode;
    std::string paramName;
    SourceRange bodyRange;
};

class TemplateRegistry {
public:
    std::map<std::string, TemplateBlueprint> blueprints;

    void RegisterBlueprint(ClassTemplateDecl* decl, SourceManager& sm, const LangOptions& langOpts) {
        std::string name = decl->getNameAsString();
        
        auto* paramList = decl->getTemplateParameters();
        std::string paramName = paramList->getParam(0)->getNameAsString();

        CXXRecordDecl* templatedRecord = decl->getTemplatedDecl();
        SourceRange range = templatedRecord->getSourceRange();
        
        StringRef sourceText = Lexer::getSourceText(
            CharSourceRange::getTokenRange(range), sm, langOpts
        );

        blueprints[name] = { sourceText.str(), paramName, range };
    }

    bool HasBlueprint(const std::string& name) {
        return blueprints.find(name) != blueprints.end();
    }
};