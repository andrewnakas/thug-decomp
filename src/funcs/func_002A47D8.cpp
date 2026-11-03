struct SkBase_002A47D8 {
    char pad[0x14];
};

struct SkMid_002A47D8 : SkBase_002A47D8 {
    virtual ~SkMid_002A47D8();
};

struct Sk_002A47D8 : SkMid_002A47D8 {
    ~Sk_002A47D8();
    int m18;
    char pad1C[0x14];
    int m30;
};

struct Obj_002A47D8;
extern char D_00378480[];
extern char D_00392130[];
extern char D_00392138[];
extern char D_00378490[];
extern char D_003784A0[];
extern "C" Sk_002A47D8* func_002A49B8(Obj_002A47D8* o);
extern "C" Sk_002A47D8* func_002A56E0(Obj_002A47D8* o);
extern "C" void func_002A4A58(Obj_002A47D8* o, Sk_002A47D8* s);
extern "C" int func_002B2F30(Sk_002A47D8* s);
extern "C" void func_00268100(void* p);
extern "C" int func_002B22B8(Sk_002A47D8* s);
extern "C" int func_002B22C8(Sk_002A47D8* s);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" int func_001F0D78(char* s);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" void func_001E7A30(void* s, int name, int type, char* v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" int func_002B1FE8(Sk_002A47D8* s);
extern "C" void func_002B2310(Sk_002A47D8* s);

struct Obj_002A47D8 {
    char pad[0x74];
    void* m74;
    char pad78[0x1A8 - 0x78];
    Sk_002A47D8* m1A8;
    void Remove(Sk_002A47D8* s);
};

void Obj_002A47D8::Remove(Sk_002A47D8* s)
{
    if (s == m1A8) {
        m1A8 = func_002A49B8(this);
        if (s == m1A8) m1A8 = 0;
        Sk_002A47D8* e = func_002A56E0(this);
        if (e && e->m18) func_002A4A58(this, e);
        else func_002A4A58(this, m1A8);
    }
    if (func_002B2F30(s) && m74) func_00268100(m74);
    if (func_002B22B8(s)) {
        int id = func_002B22C8(s);
        char buf[0x40];
        func_003331D0(buf, D_00378480, id + 1);
        void* p = func_001E6978(func_001190D0(8));
        func_001E7268(p, D_00392130, id);
        func_001E7A30(p, func_001F0D78(D_00392138), 3, func_001E54B8(buf, 0));
        func_001F0370(D_00378490, p, 0, 0);
        if (p) func_001E6AE8(p, 3);
        Sk_002A47D8* me = func_002A56E0(this);
        if (me && !func_002B1FE8(me) && me->m30 == id) func_001F0370(D_003784A0, 0, 0, 0);
        func_002B2310(s);
    }
    delete s;
}
