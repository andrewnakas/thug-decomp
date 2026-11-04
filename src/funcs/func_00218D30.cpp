extern char D_00370EC8[];

struct Script_00218D30 {
    char pad[0x18];
    void* m_params;
};

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int size, int type);
extern "C" void func_001E90A8(void* arr, int i, int value);
extern "C" void func_001E76D8(void* params, const char* name, void* arr);
extern "C" void func_001E6518(void* arr);
extern "C" void func_001E8DE8(void* arr, int flags);

bool Cmd_00218D30(void* params, Script_00218D30* script)
{
    int n;
    func_001E7DE8(params, 0, &n, 1);
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, n, 1);
    for (int i = 0; i < n; i++)
        func_001E90A8(arr, i, i);
    func_001E76D8(script->m_params, D_00370EC8, arr);
    func_001E6518(arr);
    if (arr)
        func_001E8DE8(arr, 3);
    return true;
}
