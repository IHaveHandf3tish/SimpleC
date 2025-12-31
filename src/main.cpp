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