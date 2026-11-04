extern char D_00371C78[];

struct Iter_002AA0E0 {
    int m0;
    int m4;
    void* m8;
    Iter_002AA0E0() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002AA0E0() { m8 = D_00371C78; }
};

struct Pool_002AA0E0 {
    char pad0[0xE4];
    int mE4;
};

struct Table_002AA0E0 {
    char pad0[0xC];
    void* mC;
};

struct Elem_002AA0E0 {
    char pad0[0x28];
    int m28;
    char pad2C[0x34 - 0x2C];
    char m34[4];
};

extern Pool_002AA0E0* D_00388A70;
extern Table_002AA0E0* D_00392068;
extern char D_003921F0[];
extern char D_00392090[];
extern char D_003920C0[];
extern char D_00378AB8[];
extern char D_00378AE0[];
extern char D_00378AC8[];
extern char D_00378AF8[];
extern char D_003921D8[];
extern char D_00392120[];
extern char D_00378B08[];
extern char D_00378B20[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" Elem_002AA0E0* func_002A53F8(void* self, Iter_002AA0E0* it, int a);
extern "C" Elem_002AA0E0* func_002A5490(void* self, Iter_002AA0E0* it, int a);
extern "C" int func_002B1FC8(Elem_002AA0E0* e);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* a, int n, int t);
extern "C" void func_001E90A8(void* a, int i, int v);
extern "C" void func_001E8DE8(void* a, int v);
extern "C" int func_002D7EB8(void* p);
extern "C" int func_002D8160(void* p, int id);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E73C8(void* p, char* name, int v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E76D8(void* p, char* name, void* v);
extern "C" void func_001E7860(void* p, char* name, void* v);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

struct Obj_002AA0E0 {
    bool Refresh();
};

bool Obj_002AA0E0::Refresh()
{
    Iter_002AA0E0 it;
    Table_002AA0E0* t = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->mE4);
    int i = 0;
    for (Elem_002AA0E0* e = func_002A53F8(t, &it, 1); e; e = func_002A5490(t, &it, 1)) {
        if (func_002B1FC8(e)) {
            i++;
            continue;
        }
        void* arr = func_001E8DD0(func_00122CF8(0x10));
        func_001E8E98(arr, 4, 1);
        if (e->m28 && func_002D7EB8(t->mC)) {
            if (func_002D8160(t->mC, e->m28)) {
                func_001E90A8(arr, 0, 0x80);
                func_001E90A8(arr, 1, 0x80);
                func_001E90A8(arr, 2, 0);
                func_001E90A8(arr, 3, 0x80);
            } else {
                func_001E90A8(arr, 0, 0);
                func_001E90A8(arr, 1, 0x80);
                func_001E90A8(arr, 2, 0);
                func_001E90A8(arr, 3, 0x80);
            }
        } else {
            func_001E90A8(arr, 0, 0x80);
            func_001E90A8(arr, 1, 0x80);
            func_001E90A8(arr, 2, 0x80);
            func_001E90A8(arr, 3, 0x80);
        }
        void* p = func_001E6978(func_001190D0(8));
        func_001E7138(p, D_003920C0, e->m34);
        func_001E73C8(p, D_00378AB8, 0x2A434D05);
        func_001E73C8(p, D_00392090, i + 123456);
        func_001E73C8(p, D_00378AC8, func_001F0D78(D_00378AE0));
        void* q = func_001E6978(func_001190D0(8));
        func_001E76D8(q, D_003921F0, arr);
        func_001E76D8(p, D_003921F0, arr);
        func_001E7860(p, D_00378AF8, q);
        void* r = func_001E6978(func_001190D0(8));
        func_001E7268(r, D_003921D8, i);
        func_001E7138(r, D_00392120, e->m34);
        func_001E7860(p, D_00378B08, r);
        func_001F0370(D_00378B20, p, 0, 0);
        if (p) func_001E6AE8(p, 3);
        if (r) func_001E6AE8(r, 3);
        if (q) func_001E6AE8(q, 3);
        if (arr) func_001E8DE8(arr, 3);
        i++;
    }
    func_0010A9B0(D_00388A70);
    return true;
}
