struct Obj_002ACDD8_G {
    char pad0[0xE4];
    int mE4;
};

struct Obj_002ACDD8_S {
    char pad0[0x94];
    void* m94;
    char pad98[0x158 - 0x98];
    int m158;
};

struct Obj_002ACDD8 {
    signed char* m0;
    char pad4[0x1C - 0x4];
    Obj_002ACDD8_S* m1C;
};

extern Obj_002ACDD8_G* D_00388A70;
extern char D_00378E38[];
extern char D_00378E80[];
extern char D_00378E98[];
extern char D_00378EA8[];
extern char D_00378EC8[];
extern char D_00378EE8[];
extern char D_00378F08[];
extern char D_00378F20[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_001048F0(void* p);
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" int func_001F0D78(char* s);
extern "C" int func_002A8258(Obj_002ACDD8_S* s);
extern "C" void func_002A3510(Obj_002ACDD8_S* s);
extern "C" void func_002A8250(Obj_002ACDD8_S* s, int v);

int func_002ACDD8(Obj_002ACDD8* p)
{
    Obj_002ACDD8_S* s = p->m1C;
    switch (*p->m0) {
    case 4:
        s->m158 = func_001F0D78(D_00378E80);
        break;
    case 0:
        s->m158 = func_001F0D78(D_00378E98);
        break;
    case 5:
        s->m158 = func_001F0D78(D_00378E38);
        break;
    case 1:
        if (func_002A8258(s) == 4) {
            s->m158 = func_001F0D78(D_00378EA8);
            break;
        }
        func_0010A950(D_00388A70, D_00388A70->mE4);
        func_001F0370(D_00378EC8, 0, 0, 0);
        func_001048F0(s->m94);
        func_0010A9B0(D_00388A70);
        return 1;
    case 3:
        func_001F0370(D_00378EE8, 0, 0, 0);
        func_001048F0(s->m94);
        return 1;
    case 2:
        s->m158 = func_001F0D78(D_00378F08);
        break;
    default:
        s->m158 = func_001F0D78(D_00378F20);
        break;
    }
    func_002A3510(s);
    func_002A8250(s, 8);
    return 2;
}
