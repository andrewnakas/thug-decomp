struct Item_00246258 {
    char pad[0x20];
    void* m_20;
    unsigned int Get();
};

extern char D_0038FFE0[];
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);

unsigned int Item_00246258::Get()
{
    unsigned int v = 0;
    func_001E84E8(m_20, D_0038FFE0, &v, 1);
    return v;
}
