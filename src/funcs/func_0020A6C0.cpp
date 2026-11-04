typedef int qword_0020A6C0 __attribute__((mode(TI)));

struct Vec_0020A6C0 {
    union {
        qword_0020A6C0 q;
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

struct Mat_0020A6C0 {
    Vec_0020A6C0 row[4];
    const Vec_0020A6C0& operator[](int i) const { return row[i]; }
    Mat_0020A6C0& operator=(const Mat_0020A6C0& o)
    {
        row[0] = o[0];
        row[1] = o[1];
        row[2] = o[2];
        row[3] = o[3];
        return *this;
    }
};

struct Body_0020A6C0 {
    char pad0[0x50];
    Vec_0020A6C0 m_pos;
    char pad60[0x10];
    Mat_0020A6C0 m_mat;
};

struct Snap_0020A6C0 {
    Body_0020A6C0* m_body;
    int m_4;
    int m_8;
    int padC;
    Mat_0020A6C0 m_mat;
    Vec_0020A6C0 m_pos;
    Vec_0020A6C0 m_vel;
    char pad70[0x40];
    int m_B0;
};

extern "C" void func_00183C98(Body_0020A6C0* b, Snap_0020A6C0* ref);

Snap_0020A6C0* func_0020A6C0(Snap_0020A6C0* self, Body_0020A6C0* body)
{
    self->m_4 = 0;
    self->m_8 = 0;
    self->m_body = body;
    if (body)
        func_00183C98(body, self);
    self->m_mat = self->m_body->m_mat;
    self->m_pos = self->m_body->m_pos;
    self->m_vel.Set(0.0f, 0.0f, 0.0f, 1.0f);
    self->m_B0 = 0;
    return self;
}
