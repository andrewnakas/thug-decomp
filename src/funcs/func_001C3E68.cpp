typedef unsigned int u128 __attribute__((mode(TI)));

union Vec_001C3E68 {
    struct {
        float x, y, z, w;
    } f;
    u128 q;
};

struct Coll_001C3E68 {
    char m_pad[0x28];
    int m28;
};

struct Phys_001C3E68 {
    char m_pad[0x14C];
    int m14C;
};

struct Obj_001C3E68 {
    char m_pad[0x30];
    char m30[0x10];
    Vec_001C3E68 m40;
    float m50;
    char m_pad54[0x80 - 0x54];
    char m80[0x10];
    unsigned int m90;
    char m_pad94[0xC0 - 0x94];
    int mC0;
    char m_padC4[0x9B0 - 0xC4];
    int m9B0;
    char m_pad9B4[0x9E0 - 0x9B4];
    char m9E0[0xA28 - 0x9E0];
    Phys_001C3E68* mA28;
    char m_padA2C[0xA38 - 0xA2C];
    Coll_001C3E68* mA38;
    char m_padA3C[0xA44 - 0xA3C];
    int mA44;
};

extern "C" int func_002817F0(int world, int flags, void* a, void* b, Vec_001C3E68* pos, void* out);

extern "C" bool func_001C3E68(Obj_001C3E68* self)
{
    if (self->mC0)
        return false;
    if (self->mA38->m28)
        return false;
    if (self->mA28->m14C) {
        Vec_001C3E68 p;
        p.f.x = self->m40.f.x;
        p.f.y = self->m50;
        p.f.z = self->m40.f.z;
        p.f.w = 1.0f;
        if (func_002817F0(self->mA44, 0, self->m30, self->m80, &p, self->m9E0)) {
            self->m40.q = p.q;
            self->m50 = p.f.y;
            self->m9B0 = 2;
            self->m40.f.y = 0.0f;
            self->m90 = 0x2EDA83EA;
            return true;
        }
    }
    return false;
}
