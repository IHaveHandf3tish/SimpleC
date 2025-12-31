/*
Parse import statements in .sc files
Resolve relative paths (import "../utils/helpers.sc")
Search standard library paths (import "std/array.sc" finds std/array.sc)
Handle name conflicts (two imports with same name)
Build the input for DependencyGraph
Track which symbols are imported from each module
*/