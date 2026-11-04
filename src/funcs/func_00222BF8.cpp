extern char D_0038F918[];
extern char D_0038F8F0[];
extern char D_0038F920[];

struct Script_00222BF8 {
    char pad[0x18];
    void* m_params;
};

struct Array_00222BF8 {
    char pad[0xC];
    int m_size;
};

extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" Array_00222BF8* func_001E55B8(unsigned int key, int a);
extern "C" bool func_001E8398(void* params, unsigned int key, unsigned int* out, int required);
extern "C" bool func_001E7E58(void* params, char* name, int* out, int required);
extern "C" void* func_001E9378(Array_00222BF8* a, int i);
extern "C" bool func_001E8618(void* params, unsigned int key);
extern "C" void func_001E7268(void* params, char* name, int value);

bool func_00222BF8(void* params, Script_00222BF8* script)
{
    unsigned int name;
    func_001E84E8(params, D_0038F918, &name, 1);
    Array_00222BF8* arr = func_001E55B8(name, 1);
    unsigned int key;
    func_001E8398(params, 0xA1DC81F9, &key, 1);
    int i = 0;
    func_001E7E58(params, D_0038F8F0, &i, 0);
    unsigned int want;
    func_001E84E8(params, D_0038F920, &want, 1);
    int n = arr->m_size;
    for (; i < n; i++) {
        void* e = func_001E9378(arr, i);
        if (func_001E8618(e, key)) {
            unsigned int v;
            func_001E8398(e, key, &v, 1);
            if (v == want) {
                func_001E7268(script->m_params, D_0038F8F0, i);
                return true;
            }
        }
    }
    return false;
}
