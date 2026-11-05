extern "C" int func_001E8870(void* params, unsigned int id, char** out, int req);
extern "C" void* func_001394A0(void* node, char* name);
extern "C" void func_001388F0(void* c);
extern "C" bool func_001390E0(void* node, void* c);
extern "C" void func_00103F28(char* fmt, ...);
extern void* D_00393EF8;
extern char D_0035E000[];

bool Cmd_0013A8F0(void* params, void* script)
{
    char* name;
    func_001E8870(params, 0, &name, 0);
    void* c = func_001394A0(D_00393EF8, name);
    if (c) {
        func_001388F0(c);
        func_001390E0(D_00393EF8, c);
    } else {
        func_00103F28(D_0035E000, name);
    }
    return true;
}
