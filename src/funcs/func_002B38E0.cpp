struct LNode_002B38E0 {
    int m0;
    int m4;
    int m8;
    LNode_002B38E0* mC;
    LNode_002B38E0* m10;
};

struct Srv_002B38E0 : LNode_002B38E0 {
    char pad14[4];
    char m18[0x10];
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    char m44[0x20];
    char m64[0x20];
    int m84;
    int m88;
    char m8C;
    int m90;
    int m94;
};

struct Data_002B38E0 {
    signed char m0;
    signed char m1;
    signed char m2;
    signed char m3;
    signed char m4;
    signed char m5;
    signed char m6;
    signed char m7;
    char m8[0x10];
    char m18[0x20];
    char m38[0x20];
    unsigned char m58;
    char pad59[3];
    int m5C;
    char m60[1];
};

struct Mgr_002B38E0 {
    char pad[0x13C];
    LNode_002B38E0 m13C;
};

struct Heap_002B38E0 {
    char pad[0xF4];
    int mF4;
};

struct Conn_002B38E0 {
    char pad[0x4C];
    int m4C;
};

extern Heap_002B38E0* D_00388A70;
extern "C" int func_002B4F10(Mgr_002B38E0* m, char* name, int addr);
extern "C" void func_0010A950(Heap_002B38E0* p, int v);
extern "C" void func_0010A9B0(Heap_002B38E0* p);
extern "C" void* func_001046B0(int size);
extern "C" Srv_002B38E0* func_002B51A0(void* p);
extern "C" char* func_00331A9C(char* d, char* s);
extern "C" int func_0010FC30();
extern "C" void func_002B53F0(Srv_002B38E0* s, char* p, int v);

struct Obj_002B38E0 {
    Data_002B38E0* m0;
    char pad4[4];
    long m8;
    char pad10[4];
    Conn_002B38E0* m14;
    char pad18[4];
    Mgr_002B38E0* m1C;
    int Handle();
};

int Obj_002B38E0::Handle()
{
    Mgr_002B38E0* mgr = m1C;
    Data_002B38E0* d = m0;
    if (m8 != 0xE0)
        return 3;
    char* name = d->m8;
    if (func_002B4F10(mgr, name, m14->m4C))
        return 3;
    LNode_002B38E0* head = &mgr->m13C;
    func_0010A950(D_00388A70, D_00388A70->mF4);
    Srv_002B38E0* s = func_002B51A0(func_001046B0(0xC8));
    func_00331A9C(s->m18, name);
    s->m28 = m14->m4C;
    s->m30 = func_0010FC30() - d->m5C;
    func_00331A9C(s->m44, d->m18);
    func_00331A9C(s->m64, d->m38);
    s->m38 = d->m1;
    s->m34 = d->m0;
    s->m40 = d->m3;
    s->m3C = d->m2;
    s->m84 = d->m4 != 0;
    s->m88 = d->m5 != 0;
    s->m90 = d->m6;
    s->m94 = d->m7 != 0;
    s->m8C = d->m58;
    s->m2C = 0x141E;
    for (int i = 0; i < s->m34; i++)
        func_002B53F0(s, d->m60 + i * 0x10, 0);
    s->m10 = head->m10;
    s->mC = head;
    head->m10->mC = s;
    head->m10 = s;
    func_0010A9B0(D_00388A70);
    return 1;
}
