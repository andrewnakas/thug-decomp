typedef int qword_001D74B8 __attribute__((mode(TI)));

struct Vec_001D74B8 {
    union {
        qword_001D74B8 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_001D74B8() {}
    Vec_001D74B8(float ax, float ay, float az, float aw)
    {
        f.x = ax;
        f.y = ay;
        f.z = az;
        f.w = aw;
    }
};

struct Box_001D74B8 {
    Vec_001D74B8 min;
    Vec_001D74B8 max;
};

struct Obj_001D74B8 {
    char pad0[0x10];
    Vec_001D74B8 m_pos;
    char pad20[0x90];
    float m_radius;
    bool m_dirty;
    char padB8[8];
    Box_001D74B8 m_box;

};

Box_001D74B8* func_001D74B8(Obj_001D74B8* self)
{
    if (self->m_dirty) {
        float r = self->m_radius;
        self->m_dirty = false;
        self->m_box.min = Vec_001D74B8(-r + self->m_pos.f.x, -r + self->m_pos.f.y, -r + self->m_pos.f.z, 1.0f);
        self->m_box.max = Vec_001D74B8(r + self->m_pos.f.x, r + self->m_pos.f.y, r + self->m_pos.f.z, 1.0f);
    }
    return &self->m_box;
}
