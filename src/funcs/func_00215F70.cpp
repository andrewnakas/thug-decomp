struct Script_00215F70 {
    char pad[0x18];
    void* m18;
};

extern void* D_0038FC78;
extern "C" void* func_0022E358(void* g);
extern "C" int func_0024F8A0(void* p);
extern "C" void func_001E7200(void* s, unsigned int name, int v);

extern "C" bool func_00215F70(void* params, Script_00215F70* script)
{
    void* s = script->m18;
    func_001E7200(s, 0x651533EC, func_0024F8A0(func_0022E358(D_0038FC78)));
    return true;
}
