extern char D_0038F928[];
extern char D_00371BA0[];
extern int D_0038FC78;

struct Script_00223170 {
    char pad[0x18];
    void* m_params;
};

struct Array_00223170 {
    char pad[0xC];
    int m_size;
};

struct Entry_00223170 {
    int a;
    unsigned int key;
    int value;
};

extern "C" bool func_001E82B8(void* params, char* name, Array_00223170** out, int required);
extern "C" void* func_0022E368(int a, int b);
extern "C" void* func_00262330(void* a, unsigned int key);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int size, int type);
extern "C" unsigned int func_001E9300(Array_00223170* a, int i);
extern "C" int func_00221FA0(void* a, unsigned int key, int b);
extern "C" int func_00261F80(void* a);
extern "C" Entry_00223170 func_00261FB0(void* a, int i);
extern "C" void func_001E90F8(void* arr, int i, int value);
extern "C" void func_001E76D8(void* params, char* name, void* arr);

bool func_00223170(void* params, Script_00223170* script)
{
    Array_00223170* src;
    func_001E82B8(params, D_0038F928, &src, 1);
    void* mgr = func_0022E368(D_0038FC78, 0);
    void* obj = func_00262330(mgr, 0xD544AA2D);
    int n = src->m_size;
    void* out = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(out, n, 0xD);
    for (int i = 0; i < n; i++) {
        unsigned int key = func_001E9300(src, i);
        int v = func_00221FA0(obj, key, 0);
        if (!v) {
            int m = func_00261F80(mgr);
            for (int j = 0; j < m; j++) {
                Entry_00223170 e = func_00261FB0(mgr, j);
                if (e.key == key) {
                    v = e.value;
                    break;
                }
            }
        }
        func_001E90F8(out, i, v);
    }
    func_001E76D8(script->m_params, D_00371BA0, out);
    return true;
}
