struct Vec_001F37E0 {
    float x, y, z, w;
    void Set(float nx, float ny, float nz, float nw)
    {
        x = nx;
        y = ny;
        z = nz;
        w = nw;
    }
};

extern char D_003662E0[];

struct Comp_001F37E0 {
    char pad0[4];
    unsigned int m_type;
    char pad8[0x10];
    void* m_vtbl;
    char pad1C[0xA14];
    Vec_001F37E0 m_A30;
    Vec_001F37E0 m_A40;
    char padA50[0x20];
    Vec_001F37E0 m_A70;
    Vec_001F37E0 m_A80;
    char padA90[0x10];
    int m_AA0;
    int m_AA4;
    int m_AA8;
    int m_AAC;
};

extern "C" Comp_001F37E0* func_00184DC0(Comp_001F37E0* self);

Comp_001F37E0* func_001F37E0(Comp_001F37E0* self)
{
    func_00184DC0(self);
    self->m_vtbl = D_003662E0;
    self->m_type = 0x4FF8DAC6;
    self->m_AA0 = 0;
    self->m_AA4 = 0;
    self->m_AA8 = 0;
    self->m_AAC = 0;
    self->m_A30.Set(0.0f, 0.0f, 0.0f, 0.0f);
    self->m_A40.Set(0.0f, 0.0f, 0.0f, 0.0f);
    self->m_A70.Set(0.0f, 0.0f, 0.0f, 0.0f);
    self->m_A80.Set(0.0f, 0.0f, 0.0f, 0.0f);
    return self;
}
