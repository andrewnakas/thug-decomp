struct Msg_002A4C10 {
    unsigned char m0;
    char pad1[0xC - 1];
    int mC;
    unsigned char m10;
    char pad11[0x20 - 0x11];
};

struct Elem_002A4C10;
extern "C" void func_001FA800(Msg_002A4C10* m);
extern "C" void func_00200C00(void* q, Msg_002A4C10* m);
extern "C" int func_002B1FE8(Elem_002A4C10* e);

struct Obj_002A4C10;
extern "C" Elem_002A4C10* func_002A56E0(Obj_002A4C10* o);

struct Obj_002A4C10 {
    char pad0[0x18];
    void* m18;
    void Notify();
};

void Obj_002A4C10::Notify()
{
    Msg_002A4C10 m;
    func_001FA800(&m);
    if (!func_002B1FE8(func_002A56E0(this))) {
        m.m0 = 0x4A;
        m.mC = 2;
        m.m10 = 8;
        func_00200C00(m18, &m);
    }
}
