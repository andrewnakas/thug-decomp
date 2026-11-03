extern char D_00378FB0[];
extern char D_00392298[];
extern char D_003922A0[];
extern char D_00378FC0[];
extern char D_00378FD0[];
extern char D_00378FF0[];

struct Elem_002AE790 {
    char pad0[0x30];
    int m30;
};

extern "C" Elem_002AE790* func_002A52F0(void* s, unsigned short id);
extern "C" int func_002B22B8(Elem_002AE790* e);
extern "C" int func_002B22C8(Elem_002AE790* e);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" int func_001E54B8(char* s, int v);
extern "C" void func_001E7A30(void* p, int name, int type, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" int func_002B1FC8(Elem_002AE790* e);
extern "C" int func_002B1FE8(Elem_002AE790* e);
extern "C" Elem_002AE790* func_002A56E0(void* t);
extern "C" void func_002B2310(Elem_002AE790* e);
extern "C" int func_001F0D78(char* s);

struct Obj_002AE790 {
    signed char* m0;
    char pad[0x18];
    void* m1C;
};

bool Cmd_002AE790(Obj_002AE790* o)
{
    void* t = o->m1C;
    Elem_002AE790* e = func_002A52F0(t, *o->m0);
    if (e && func_002B22B8(e)) {
        char buf[64];
        int id = func_002B22C8(e);
        func_003331D0(buf, D_00378FB0, id + 1);
        void* p = func_001E6978(func_001190D0(8));
        func_001E7268(p, D_00392298, id);
        func_001E7A30(p, func_001F0D78(D_003922A0), 3, func_001E54B8(buf, 0));
        func_001F0370(D_00378FC0, p, 0, 0);
        if (p) func_001E6AE8(p, 3);
        if (func_002B1FC8(e)) func_001F0370(D_00378FD0, 0, 0, 0);
        Elem_002AE790* x = func_002A56E0(t);
        if (x && !func_002B1FE8(x) && x->m30 == id) func_001F0370(D_00378FF0, 0, 0, 0);
        func_002B2310(e);
    }
    return true;
}
