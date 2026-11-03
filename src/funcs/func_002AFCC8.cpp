extern char D_00371C78[];
extern char D_00378FB0[];
extern char D_003922A0[];
extern char D_003922F0[];
extern char D_00379468[];
extern char D_00379478[];

struct Iter_002AFCC8 {
    int m0;
    int m4;
    void* m8;
    Iter_002AFCC8() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002AFCC8() { m8 = D_00371C78; }
};

struct Elem_002AFCC8 {
    char pad[0x30];
    int m30;
    char m34[4];
};

extern void* D_0038FC78;
extern "C" int func_001F0D78(char* s);
extern "C" Elem_002AFCC8* func_002A52F0(void* s, unsigned short id);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" int func_002B1FC8(void* item);
extern "C" void* func_0022E358(void* g);
extern "C" int func_0024F540(void* p);
extern "C" int func_0024F590(void* p);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" Elem_002AFCC8* func_002A53F8(void* self, Iter_002AFCC8* it, int a);
extern "C" Elem_002AFCC8* func_002A5490(void* self, Iter_002AFCC8* it, int a);
extern "C" void func_001F0210(unsigned int name, void* a, int b, int c, int d);

struct Obj_002AFCC8 {
    signed char* m0;
    char pad[0x18];
    void* m1C;
};

bool Cmd_002AFCC8(Obj_002AFCC8* o)
{
    Iter_002AFCC8 it;
    void* g = D_0038FC78;
    signed char* p = o->m0;
    void* mgr = o->m1C;
    Elem_002AFCC8* e = func_002A52F0(mgr, p[0]);
    if (e) {
        char buf[64];
        e->m30 = p[1];
        func_003331D0(buf, D_00378FB0, p[1] + 1);
        void* s = func_001E6978(func_001190D0(8));
        if (func_002B1FC8(e)) {
            if (func_0024F540(func_0022E358(g))) {
                func_001E7A30(s, func_001F0D78(D_003922A0), 3, func_001E54B8(buf, 0));
                func_001F0370(D_00379468, s, 0, 0);
            }
        } else {
            if (func_0024F540(func_0022E358(g))) {
                func_001E7A30(s, func_001F0D78(D_003922A0), 3, e->m34);
                func_001E7A30(s, func_001F0D78(D_003922F0), 3, func_001E54B8(buf, 0));
                func_001F0370(D_00379478, s, 0, 0);
            }
        }
        if (s)
            func_001E6AE8(s, 3);
        bool all = true;
        int n = 0;
        Elem_002AFCC8* q = func_002A53F8(mgr, &it, 0);
        if (q) do {
            if (q != e) {
                n++;
                if (p[1] != q->m30)
                    all = false;
            }
            q = func_002A5490(mgr, &it, 0);
        } while (q);
        if (all && n > 0) {
            if (func_0024F590(func_0022E358(g)) > 0)
                func_001F0210(0x16C9B0DC, 0, 0, 0, 0);
        }
    }
    return true;
}
