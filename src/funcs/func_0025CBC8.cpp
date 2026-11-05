typedef int qword_0025CBC8 __attribute__((mode(TI)));

struct Vec_0025CBC8 {
    union {
        qword_0025CBC8 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_0025CBC8(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

struct Obj_0025CBC8 {
    char pad0[0x50];
    Vec_0025CBC8 m_pos;
};

struct WorldBase_0025CBC8 {
    char pad0[0x2C];
    virtual void Func0();
    virtual void Add(Obj_0025CBC8* o);
};

extern void* D_0038FC78;

extern "C" WorldBase_0025CBC8* func_0022E040(void* mgr);
extern "C" void* func_001046B0(unsigned int size);
extern "C" Obj_0025CBC8* func_00184EB8(void* mem);
extern "C" void func_00183F08(Obj_0025CBC8* o, int type);
extern "C" void func_001F0210(unsigned int script, void* params, Obj_0025CBC8* o, int a, int b);
extern "C" void func_00185500(Obj_0025CBC8* o);

Obj_0025CBC8* func_0025CBC8(void* params)
{
    WorldBase_0025CBC8* world = func_0022E040(D_0038FC78);
    Obj_0025CBC8* o = func_00184EB8(func_001046B0(0x110));
    func_00183F08(o, 0xB);
    world->Add(o);
    func_001F0210(0x1F29C5A5, params, o, 0, 0);
    func_00185500(o);
    o->m_pos = Vec_0025CBC8(0.0f, 0.0f, 0.0f, 1.0f);
    return o;
}
