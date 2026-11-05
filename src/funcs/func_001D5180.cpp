typedef int qword_001D5180 __attribute__((mode(TI)));

struct Vec_001D5180 {
    union {
        qword_001D5180 q;
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

struct Box_001D5180 {
    Vec_001D5180 min;
    Vec_001D5180 max;
};

extern char D_00364040[];

struct Obj_001D5180 {
    char pad0[0xC];
    void* m_vtbl;
    char pad10[0xA0];
    Box_001D5180 m_box;
    int m_D0;
    short m_D4;
};

extern "C" Obj_001D5180* func_001D4CC8(Obj_001D5180* self);
extern "C" Box_001D5180* func_001022D8(Box_001D5180* box);

Obj_001D5180* func_001D5180(Obj_001D5180* self)
{
    func_001D4CC8(self);
    self->m_vtbl = D_00364040;
    func_001022D8(&self->m_box);
    Box_001D5180 box;
    box.min.Set(-50.0f, -20.0f, -90.0f, 1.0f);
    box.max.Set(30.0f, 36.0f, 90.0f, 1.0f);
    self->m_box = box;
    self->m_D0 = 0;
    self->m_D4 = 0;
    return self;
}
