struct P_002B07D0 {
    void* m0;
    signed char m4;
};

struct S_002B07D0 {
    char pad[0x16C];
    int m16C;
};

extern char D_003791E0[];
extern char D_003791F8[];
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void* func_001E5548(void* p, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" int func_002A1A38(S_002B07D0* s);

struct Obj_002B07D0 {
    P_002B07D0* m0;
    char pad[0x18];
    S_002B07D0* m1C;
    bool Toggle();
};

bool Obj_002B07D0::Toggle()
{
    P_002B07D0* p = m0;
    S_002B07D0* s = m1C;
    void* e = func_001E6978(func_001190D0(8));
    func_001F0370(D_003791E0, func_001E5548(p->m0, 1), 0, 0);
    func_001F0370(D_003791F8, func_001E5548(p->m0, 1), 0, 0);
    if (!func_002A1A38(s))
        s->m16C ^= 1 << p->m4;
    if (e) {
        func_001E6AE8(e, 3);
    }
    return true;
}
