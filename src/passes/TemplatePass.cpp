/*the template pass in it's part will:
Phase 1 - Collection: Scan for template definitions (structs, functions marked as generic)
Parse template syntax (your custom <T> notation or similar)
Store template "blueprints" in TemplateRegistry
Phase 2 - Discovery: Find all template instantiations in the code (Array<int>, sort<float>)
Phase 3 - Monomorphization: For each unique instantiation, generate concrete C code
Insert generated code at the top of the file (before first use)
Replace template syntax with mangled names in the original code
Handle recursive templates and circular dependencies
*/