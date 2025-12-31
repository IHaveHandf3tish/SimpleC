/*
Define a string type (better than raw char*)
Provide functions: String_create, String_from_cstr, String_concat, String_length, String_drop
Handle memory management automatically
Could be implemented as Array<char> internally
Another RAII example - String_drop frees the string buffer
*/