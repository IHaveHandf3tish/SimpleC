/* in the this util we're gonna: 
Wrap Clang's Rewriter class with a cleaner API
Provide safe insertion methods (before/after locations, inside scopes)
Handle edge cases like inserting at macro expansions
Track whether rewrites succeed or fail
Utility methods like "insert at end of function" or "replace entire statement"
*/