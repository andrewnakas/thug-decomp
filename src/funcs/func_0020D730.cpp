struct Array_0020D730 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

struct Script_0020D730 {
    char pad0[0x18];
    void* m18;
};

extern char D_0038F398[];
extern char D_00370248[];
extern char D_00370258[];
extern char D_00370268[];
extern "C" bool func_001E82B8(void* params, char* name, Array_0020D730** out, int required);
extern "C" bool func_001E87B8(void* params, char* name);
extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" void* func_00122CF8(int size);
extern "C" Array_0020D730* func_001E8DD0(void* p);
extern "C" void func_001E66C0(Array_0020D730* dst, Array_0020D730* src);
extern "C" int* func_001E9038(Array_0020D730* a);
extern "C" int func_00100030(int n);
extern "C" void func_001E7720(void* table, unsigned int name, Array_0020D730* a);

bool Cmd_0020D730(void* params, Script_0020D730* script)
{
    Array_0020D730* src = 0;
    func_001E82B8(params, D_0038F398, &src, 0);
    if (!src) return false;
    Array_0020D730* arr = src;
    bool copy = !func_001E87B8(params, D_00370248);
    unsigned int name = 0;
    Array_0020D730* fresh = 0;
    if (copy) {
        func_001E84E8(params, D_00370258, &name, 0);
        if (!name) return false;
        fresh = func_001E8DD0(func_00122CF8(0x10));
        func_001E66C0(fresh, src);
        arr = fresh;
    }
    int n = arr->m_size;
    if (n) {
        int* data = func_001E9038(arr);
        int last = data[n - 1];
        for (int i = 0; i < n * 10; i++) {
            int a = func_00100030(n);
            int b = func_00100030(n);
            int t = data[a];
            data[a] = data[b];
            data[b] = t;
        }
        if (func_001E87B8(params, D_00370268) && n >= 2 && data[0] == last) {
            int j = func_00100030(n - 1) + 1;
            int t = data[0];
            data[0] = data[j];
            data[j] = t;
        }
    }
    if (copy) {
        func_001E7720(script->m18, name, fresh);
    }
    return true;
}
