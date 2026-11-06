typedef int qword_001D6A08 __attribute__((mode(TI)));

struct Vec_001D6A08 {
    union {
        qword_001D6A08 q;
        struct {
            float x, y, z, w;
        } f;
    };
    Vec_001D6A08() {}
    Vec_001D6A08(float ax, float ay, float az, float aw)
    {
        f.x = ax;
        f.y = ay;
        f.z = az;
        f.w = aw;
    }
};

struct Box_001D6A08 {
    Vec_001D6A08 min;
    Vec_001D6A08 max;
};

struct Obj_001D6A08 {
    char pad0[0x10];
    Vec_001D6A08 m_pos;
    char pad20[0x90];
    float m_radius;
    bool m_dirty;
    char padB8[8];
    Box_001D6A08 m_box;

};

bool func_001D6A08(Obj_001D6A08* self, const Box_001D6A08* o)
{
    if (self->m_dirty) {
        float r = self->m_radius;
        self->m_dirty = false;
        self->m_box.min = Vec_001D6A08(-r + self->m_pos.f.x, -r + self->m_pos.f.y, -r + self->m_pos.f.z, 1.0f);
        self->m_box.max = Vec_001D6A08(r + self->m_pos.f.x, r + self->m_pos.f.y, r + self->m_pos.f.z, 1.0f);
    }
    if (o->min.f.x > self->m_box.max.f.x || self->m_box.min.f.x > o->max.f.x || o->min.f.z > self->m_box.max.f.z ||
        self->m_box.min.f.z > o->max.f.z || o->min.f.y > self->m_box.max.f.y || self->m_box.min.f.y > o->max.f.y)
        return false;
    return true;
}
