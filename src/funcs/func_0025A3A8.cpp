typedef int qword_0025A3A8 __attribute__((mode(TI)));

struct Vec_0025A3A8 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_0025A3A8 q;
    };
    Vec_0025A3A8() {}
    Vec_0025A3A8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Obj_0025A3A8 {
    char pad[0x50];
    Vec_0025A3A8 m_pos;
};

struct Trail_0025A3A8 {
    char pad0[0x10];
    Vec_0025A3A8 m_points[64];
    int m_count;
    int m_index;
    unsigned int m_target;
    int pad41C;
    Vec_0025A3A8 m_cur;
    Vec_0025A3A8 OffsetFromCur(const Vec_0025A3A8& a) const
    {
        return Vec_0025A3A8(a.x - m_cur.x, a.y - m_cur.y, a.z - m_cur.z, a.w - m_cur.w);
    }
};

extern "C" Obj_0025A3A8* func_00184D70(unsigned int);

void func_0025A3A8(Trail_0025A3A8* self)
{
    Obj_0025A3A8* obj = func_00184D70(self->m_target);
    if (!obj)
        return;
    self->m_cur = obj->m_pos;
    if (!self->m_count) {
        self->m_points[0] = self->m_cur;
        self->m_count = 1;
        self->m_index = 0;
        return;
    }
    Vec_0025A3A8 d = self->OffsetFromCur(self->m_points[self->m_index]);
    if (d.x * d.x + d.y * d.y + d.z * d.z > 1600.0f) {
        int n = self->m_index + 1;
        self->m_index = n;
        if (n >= 64)
            self->m_index = 0;
        self->m_points[self->m_index] = self->m_cur;
        if (self->m_count < 64)
            self->m_count = self->m_count + 1;
    }
}
