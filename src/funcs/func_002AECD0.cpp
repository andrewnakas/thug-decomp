struct Msg_002AECD0 {
    unsigned char type;
    char pad1[0xB];
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

struct S4_002AECD0 {
    char c[4];
};

struct Obj_002AECD0 {
    char pad[0x9C];
    void* m9C;
};

struct G_002AECD0 {
    char pad[0x3B0];
    unsigned int m3B0;
};

struct Ctx_002AECD0 {
    char* m0;
    char pad4[0xC];
    void* m10;
    char pad14[4];
    unsigned int m18;
    Obj_002AECD0* m1C;
};

extern G_002AECD0* D_0038FC78;
extern "C" void func_001FA800(Msg_002AECD0* m);
extern "C" void func_001048F0(void* p);
extern "C" void func_002A8250(void* s, int v);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void func_001F0210(unsigned int name, void* a, int b, int c, int d);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_00200C00(void* w, Msg_002AECD0* m);
extern "C" void* func_002977B0();
extern "C" void func_00295640(void* p, int id, char* data);

int Handler_002AECD0(Ctx_002AECD0* c)
{
    Msg_002AECD0 msg;
    func_001FA800(&msg);
    G_002AECD0* g = D_0038FC78;
    Obj_002AECD0* o = c->m1C;
    if (c->m18 & 4) {
        if (g->m3B0 == 0x9F2BAFB7) {
            func_001048F0(o->m9C);
            func_002A8250(o, 2);
            void* s = func_001E6978(func_001190D0(8));
            func_001E7360(s, 0, 0x19ECA78E);
            func_001F0210(0x60B653DB, s, 0, 0, 0);
            if (s)
                func_001E6AE8(s, 3);
            return 4;
        }
        msg.type = 0x8A;
        msg.mC = 2;
        msg.m10 = 8;
        func_00200C00(c->m10, &msg);
        return 3;
    }
    int id;
    *(S4_002AECD0*)&id = *(S4_002AECD0*)c->m0;
    char* data = c->m0 + 4;
    func_00295640(func_002977B0(), id, data);
    void* s = func_001E6978(func_001190D0(8));
    func_001E7360(s, 0, 0x88001327);
    func_001F0210(0x6F4180D0, s, 0, 0, 0);
    if (s)
        func_001E6AE8(s, 3);
    return 1;
}
