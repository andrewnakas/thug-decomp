extern void* D_0038FC78;

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" char* func_0022E3C8(void* mgr, int id);
extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void* func_001200E0(void* data);
extern "C" void func_00122E40(void* s, const char* name, bool flag);

bool func_0021F0B0(void* params)
{
    int index;
    const char* name;
    func_001E7DE8(params, 0x67E6859A, &index, 1);
    char* data = func_0022E3C8(D_0038FC78, index) + 4;
    func_001E8870(params, 0x7D99F28D, &name, 1);
    bool flag = func_001E8708(params, 0x54C2E57C);
    func_00122E40(func_001200E0(data), name, flag);
    return true;
}
