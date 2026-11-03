extern char D_00371C78[];

struct Iter_002AA420 {
    int m0;
    int m4;
    void* m8;
    Iter_002AA420() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002AA420() { m8 = D_00371C78; }
};

struct Elem_002AA420 {
    char pad[0x34];
    char m34[0x14C - 0x34];
    unsigned int m14C;
};

extern void* D_00392068;
extern char D_003921D8[];
extern char D_00392120[];
extern char D_00378B38[];
extern "C" int func_001F0D78(char* s);
extern "C" int func_001E7DE8(void* p, int key, int* out, int req);
extern "C" int func_001E7C80(void* p, int key, char** out, int req);
extern "C" Elem_002AA420* func_002A53F8(void* self, Iter_002AA420* it, int a);
extern "C" Elem_002AA420* func_002A5490(void* self, Iter_002AA420* it, int a);
extern "C" int func_00336228(char* a, char* b);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

bool Cmd_002AA420(void* params, void* script)
{
    Iter_002AA420 it;
    int n = 0;
    char* name = 0;
    void* mgr = D_00392068;
    func_001E7DE8(params, func_001F0D78(D_003921D8), &n, 0);
    func_001E7C80(params, func_001F0D78(D_00392120), &name, 0);
    for (Elem_002AA420* e = func_002A53F8(mgr, &it, 0); e; e = func_002A5490(mgr, &it, 0)) {
        if (n == 0) {
            if (func_00336228(e->m34, name) == 0) {
                e->m14C |= 0x400;
                void* s = func_001E6978(func_001190D0(8));
                func_001E7A30(s, func_001F0D78(D_00392120), 3, name);
                func_001F0370(D_00378B38, s, 0, 0);
                if (s) func_001E6AE8(s, 3);
            }
            break;
        }
        n--;
    }
    return true;
}
