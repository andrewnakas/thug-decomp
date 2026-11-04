struct Desc_0021F008 {
    char m_data[0x40];
};

extern void* D_0038FC78;
extern char D_00371780[];

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" char* func_0022E3C8(void* mgr, int id);
extern "C" void* func_001200E0(void* data);
extern "C" bool func_001E81F0(void* params, const char* name, void** out, int required);
extern "C" bool func_001228A8(Desc_0021F008* d, void* params);
extern "C" void func_001E93D0(void* params, int a);
extern "C" void func_001234B8(void* obj, Desc_0021F008* d);

bool func_0021F008(void* params)
{
    Desc_0021F008 desc;
    int index;
    void* src;
    func_001E7DE8(params, 0x67E6859A, &index, 1);
    void* obj = func_001200E0(func_0022E3C8(D_0038FC78, index) + 4);
    if (!func_001E81F0(params, D_00371780, &src, 0))
        src = params;
    if (!func_001228A8(&desc, src))
        func_001E93D0(params, 0);
    func_001234B8(obj, &desc);
    return true;
}
