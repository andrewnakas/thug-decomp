struct S_002436F8 {
    char m_pad[0x18];
    void* m18;
};
struct M_002436F8 {
    char m_pad[0x50];
    int m50;
};
extern "C" M_002436F8* func_00240850();
extern "C" void func_001E7360(void* a, unsigned int name, int v);

extern "C" int func_002436F8(void* params, S_002436F8* script)
{
    func_001E7360(script->m18, 0x7E73362B, func_00240850()->m50);
    return 1;
}
