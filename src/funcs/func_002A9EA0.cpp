extern char D_00371C78[];
extern char D_003921D8[];
extern char D_00392120[];
extern char D_003921E0[];
extern char D_003921E8[];
extern char D_00378A70[];
extern char D_00378A88[];
extern char D_00378A98[];

struct Iter_002A9EA0 {
    int m0;
    int m4;
    void* m8;
    Iter_002A9EA0() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A9EA0() { m8 = D_00371C78; }
};

struct Mgr_002A9EA0 {
    char pad[0xC];
    void* mC;
};

struct Elem_002A9EA0 {
    char pad[0x28];
    int m28;
    char pad2[0x34 - 0x2C];
    char m34[0x14C - 0x34];
    unsigned int m14C;
};

extern Mgr_002A9EA0* D_00392068;
extern "C" int func_001F0D78(char* s);
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" int func_001E7C80(void* p, unsigned int key, char** out, int req);
extern "C" Elem_002A9EA0* func_002A53F8(Mgr_002A9EA0* self, Iter_002A9EA0* it, int a);
extern "C" Elem_002A9EA0* func_002A5490(Mgr_002A9EA0* self, Iter_002A9EA0* it, int a);
extern "C" int func_00336228(char* a, char* b);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" int func_002A1A28(Mgr_002A9EA0* s);
extern "C" int func_002D7EB8(void* p);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" int func_002D8160(void* p, int v);
extern "C" void func_001E7360(void* s, int name, int v);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

bool Cmd_002A9EA0(void* params, void* script)
{
    Iter_002A9EA0 it;
    int n = 0;
    char* name = 0;
    Mgr_002A9EA0* mgr = D_00392068;
    func_001E7DE8(params, func_001F0D78(D_003921D8), &n, 0);
    func_001E7C80(params, func_001F0D78(D_00392120), &name, 0);
    Elem_002A9EA0* e = func_002A53F8(mgr, &it, 1);
    if (e) do {
        if (!n) {
        if (func_00336228(e->m34, name))
            break;
        e->m14C |= 0x400;
        void* s = func_001E6978(func_001190D0(8));
        if (func_002A1A28(mgr) && e->m28) {
            if (func_002D7EB8(mgr->mC)) {
                func_001E7268(s, D_003921E0, e->m28);
                func_001E7138(s, D_003921E8, e->m34);
                if (func_002D8160(mgr->mC, e->m28))
                    func_001E7360(s, 0, func_001F0D78(D_00378A70));
                else
                    func_001E7360(s, 0, func_001F0D78(D_00378A88));
            }
        }
        func_001E7A30(s, func_001F0D78(D_00392120), 3, name);
        func_001F0370(D_00378A98, s, 0, 0);
        if (s)
            func_001E6AE8(s, 3);
        break;
        }
        n--;
        e = func_002A5490(mgr, &it, 1);
    } while (e);
    return true;
}
