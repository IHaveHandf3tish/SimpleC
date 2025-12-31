/*
Build a graph of module dependencies (which files import which)
Nodes = modules/files, Edges = import relationships
Detect circular dependencies (A imports B, B imports A)
Perform topological sort to find valid compilation order
Report errors when cycles exist that can't be resolved
*/