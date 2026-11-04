struct Vec_002568D8 {
    float x, y, z, w;
    void Set(float nx, float ny, float nz, float nw)
    {
        x = nx;
        y = ny;
        z = nz;
        w = nw;
    }
};

extern char D_00375538[];

struct Obj_002568D8 {
    char pad0[8];
    void* m_vtbl;
    char padC[0x104];
    Vec_002568D8 m_max;
    Vec_002568D8 m_min;
    Vec_002568D8 m_offset;
};

extern "C" Obj_002568D8* func_00184EB8(Obj_002568D8* self);
extern "C" void* func_001046B0(unsigned int size);
extern "C" void* func_001A9B20(void* mem);
extern "C" void func_00185288(Obj_002568D8* self, void* comp);

Obj_002568D8* func_002568D8(Obj_002568D8* self)
{
    func_00184EB8(self);
    self->m_vtbl = D_00375538;
    self->m_max.Set(10.0f, 10.0f, 10.0f, 1.0f);
    self->m_min.Set(-10.0f, -10.0f, -10.0f, 1.0f);
    self->m_offset.Set(0.0f, 0.0f, 0.0f, 1.0f);
    func_00185288(self, func_001A9B20(func_001046B0(0x54)));
    return self;
}
