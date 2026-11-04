struct Script_00227730 {
    char pad0[0x18];
    void* m18;
};

extern unsigned int D_0038F9C8;
extern int D_0038F9C4;
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_00224C60(void* p, unsigned int name, int a);
extern "C" void* func_00240850();
extern "C" void func_0023D750(void* p);

bool func_00227730(void* params, Script_00227730* script)
{
    unsigned int name = 0;
    func_001E8398(params, 0, &name, 0);
    int flag = 0;
    func_001E7DE8(params, 0xC78DABF6, &flag, 0);
    if (flag) {
        name = D_0038F9C8;
        func_00224C60(script->m18, name, D_0038F9C4);
    } else {
        if (name == 0xB010F357) func_0023D750(func_00240850());
        func_00224C60(script->m18, name, 0);
    }
    return true;
}
