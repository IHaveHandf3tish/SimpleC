/* in this pass:
Traverse the AST looking for local variable declarations
For each variable, check if its type has a destructor function (e.g., Type_drop)
Check if the variable is marked with keep attribute (skip if true)
Find the closing brace of the variable's scope
Insert a call to Type_drop(&var) before the closing brace
Handle special cases: early returns, goto statements, exceptions in scope
Track which cleanup calls have been inserted to avoid duplicates
*/