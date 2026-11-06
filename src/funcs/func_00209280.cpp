typedef int qword_00209280 __attribute__((mode(TI)));

struct Vec_00209280 {
    union {
        qword_00209280 q;
        struct {
            float x, y, z, w;
        } f;
    };
    void Set(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

struct Vec3_00209280 {
    float x, y, z;
    void Set(float nx, float ny, float nz)
    {
        y = ny;
        z = nz;
        x = nx;
    }
};

struct Obj_00209280 {
    Vec_00209280 m_a;
    Vec_00209280 m_b;
    char pad20[0x10];
    Vec_00209280 m_scale;
    char pad40[0x80];
    Vec3_00209280 m_C0;
};

extern "C" Obj_00209280* func_00101F38(Obj_00209280* self);
extern "C" void func_00209308(Obj_00209280* self);

Obj_00209280* func_00209280(Obj_00209280* self, const Vec_00209280* a, const Vec_00209280* b)
{
    func_00101F38(self);
    self->m_C0.Set(0.0f, 0.0f, 0.0f);
    self->m_a = *a;
    self->m_b = *b;
    Vec_00209280* scale = &self->m_scale;
    scale->Set(1.0f, 1.0f, 1.0f, 1.0f);
    func_00209308(self);
    return self;
}
