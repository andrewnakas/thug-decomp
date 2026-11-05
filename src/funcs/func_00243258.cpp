struct Item_00243258 {
    char pad[0x18];
    void* m_18;
};

extern "C" void* func_00240850();
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" Item_00243258* func_0023BB00(void* owner, void* params, int create);
extern "C" void func_00249E38(void* a, bool flag);

bool Cmd_00243258(void* params, void* script)
{
    void* owner = func_00240850();
    int v = 1;
    func_001E7DE8(params, 0xCE0CA665, &v, 0);
    func_00249E38(func_0023BB00(owner, params, 1)->m_18, v != 0);
    return true;
}
