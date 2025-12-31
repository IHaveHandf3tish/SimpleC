/*
the safety pass will:
Find all struct/class variable declarations
Check if they have explicit initializers
If not initialized, insert = {0} or call a default constructor
Handle arrays of structs (need to initialize each element)
Detect and warn about potentially uninitialized pointer members
Optionally: insert runtime checks for null pointer dereferences
*/