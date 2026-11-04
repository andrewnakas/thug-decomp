extern char D_00392860[];

struct Script_002CB748 {
    char pad[0x18];
    void* m18;
};

extern "C" void* func_002C95E0(int v);
extern "C" char* func_002C8610(void* p);
extern "C" void func_001E7138(void* p, char* name, char* value);

int Cmd_002CB748(void* params, Script_002CB748* script)
{
    void* s = script->m18;
    func_001E7138(s, D_00392860, func_002C8610(func_002C95E0(1)));
    return 1;
}
