struct Vec3_0027A0E0 {
    float x, y, z;
    void Set(float nx, float ny, float nz)
    {
        y = ny;
        z = nz;
        x = nx;
    }
};

extern char D_00376C58[];

struct Comp_0027A0E0 {
    char pad0[4];
    unsigned int m_type;
    char pad8[0x10];
    void* m_vtbl;
    char pad1C[0x94];
    char m_B0[0xE0];
    char m_190[0x238];
    Vec3_0027A0E0 m_3C8;
    char pad3D4[0xAC];
    char m_480[0x110];
    int m_590;
    int m_594;
    int m_598;
    int m_59C;
    int m_5A0;
    int m_5A4;
    int m_5A8;
    int m_5AC;
    int m_5B0;
    int m_5B4;
    int m_5B8;
    int m_5BC;
};

extern "C" Comp_0027A0E0* func_00184DC0(Comp_0027A0E0* self);
extern "C" void* func_00209240(void* p);
extern "C" void* func_00102FD0(void* p);
extern "C" int func_001DAD40();

Comp_0027A0E0* func_0027A0E0(Comp_0027A0E0* self)
{
    func_00184DC0(self);
    self->m_vtbl = D_00376C58;
    func_00209240(self->m_B0);
    func_00209240(self->m_190);
    self->m_3C8.Set(0.0f, 0.0f, 0.0f);
    func_00102FD0(self->m_480);
    self->m_594 = 0;
    self->m_598 = 0;
    self->m_59C = 0;
    self->m_5A0 = 0;
    self->m_5A4 = 0;
    self->m_5A8 = 0;
    self->m_5AC = 0;
    self->m_5B0 = 0;
    self->m_5B4 = 0;
    self->m_5B8 = 0;
    self->m_5BC = 0;
    self->m_type = 0x5BD63B29;
    self->m_590 = func_001DAD40();
    return self;
}
