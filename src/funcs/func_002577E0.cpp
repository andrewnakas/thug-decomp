typedef int qword_002577E0 __attribute__((mode(TI)));

union Vec_002577E0 {
    qword_002577E0 q;
    struct {
        float x, y, z, w;
    } f;
};

struct Mat_002577E0 {
    Vec_002577E0 r[4];
};

struct Xform_002577E0 {
    Mat_002577E0 m_mat;
    Vec_002577E0 m40;
    Vec_002577E0 m_min;
    Vec_002577E0 m_max;
    Vec_002577E0 m_offset;
};

struct Obj_002577E0 {
    char m_pad[0x50];
    Vec_002577E0 m_pos;
    char m_pad60[0x114 - 0x60];
    float m114;
    char m_pad118[0x124 - 0x118];
    float m124;
};

extern "C" void func_00257068(Obj_002577E0* a, Xform_002577E0* x);
extern "C" float func_00256FC8(Obj_002577E0* a, Xform_002577E0* x);
extern "C" Vec_002577E0 func_00323298(Mat_002577E0* m, Vec_002577E0* v);
extern "C" bool func_00123558(Vec_002577E0* p, Vec_002577E0* min, Vec_002577E0* max);

static inline Vec_002577E0 operator*(Mat_002577E0& m, Vec_002577E0& v)
{
    Vec_002577E0 r = func_00323298(&m, &v);
    return r;
}

extern "C" bool func_002577E0(Obj_002577E0* a, Obj_002577E0* b, Xform_002577E0* x)
{
    Vec_002577E0 off = x->m_offset;
    func_00257068(a, x);
    Vec_002577E0 p;
    Vec_002577E0* pp = &p;
    p.f.x = b->m_pos.f.x + off.f.x;
    p.f.y = b->m_pos.f.y + off.f.y;
    p.f.z = b->m_pos.f.z + off.f.z;
    p.f.w = b->m_pos.f.w + off.f.w;
    {
        Vec_002577E0 d;
        d.f.x = p.f.x - a->m_pos.f.x;
        d.f.y = p.f.y - a->m_pos.f.y;
        d.f.z = p.f.z - a->m_pos.f.z;
        d.f.w = p.f.w - a->m_pos.f.w;
        float dist = d.f.x * d.f.x + d.f.y * d.f.y + d.f.z * d.f.z;
        if (func_00256FC8(a, x) < dist)
            return false;
    }
    p = b->m_pos;
    p.f.y += (b->m114 - b->m124) * 0.5f;
    p.f.x -= a->m_pos.f.x;
    p.f.y -= a->m_pos.f.y;
    p.f.z -= a->m_pos.f.z;
    p.f.w -= a->m_pos.f.w;
    p = x->m_mat * *pp;
    return func_00123558(pp, &x->m_min, &x->m_max);
}
