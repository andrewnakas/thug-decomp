extern "C" void func_00105260(void* p, int v);
extern "C" void func_002B5608(void* self, int mode);
extern "C" void func_001FA0C8(void* p);

struct Holder_002A7AF0 {
    int m0;
    int m4;
    int m8;
};

extern Holder_002A7AF0* D_0038C308;
extern void* D_0038EB78;

struct Obj_002A7AF0 {
    char pad0[0x90];
    int m90;
    char pad94[0x180 - 0x94];
    int m180;
    char pad184[0x1A4 - 0x184];
    int m1A4;
    void Begin(int v);
};

void Obj_002A7AF0::Begin(int v) {
    Holder_002A7AF0* h = D_0038C308;
    void* s = D_0038EB78;
    m180 = -1;
    if (v) {
        m1A4 = v;
    }
    func_00105260(&h->m8, m90);
    func_002B5608(this, 2);
    func_001FA0C8(s);
}
