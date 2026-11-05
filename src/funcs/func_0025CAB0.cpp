struct Obj_0025CAB0;
extern "C" void func_0025CA48(Obj_0025CAB0* self, int name, int a, int b);
extern "C" void* func_001046B0(int size);
extern "C" void* func_00144C38(void* p);
extern "C" void func_00144CE8(void* p, int name);

struct Ent_0025CAB0 {
    int m0;
    void* m4;
};

struct Obj_0025CAB0 {
    char pad[0x858];
    Ent_0025CAB0 m858[64];
    int mA58;
    void Fn(int name, int a, int b);
};

void Obj_0025CAB0::Fn(int name, int a, int b)
{
    Ent_0025CAB0* e = &m858[mA58];
    func_0025CA48(this, name, a, b);
    void* p = func_00144C38(func_001046B0(0xA1C));
    func_00144CE8(p, name);
    e->m4 = p;
    e->m0 = name;
    mA58++;
}
