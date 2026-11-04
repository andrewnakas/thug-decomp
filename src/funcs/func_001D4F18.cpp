typedef int qword_001D4F18 __attribute__((mode(TI)));

struct Vec_001D4F18 {
    union {
        qword_001D4F18 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Seg_001D4F18 {
    Vec_001D4F18 a;
    Vec_001D4F18 b;
};

struct Mat_001D4F18 {
    Vec_001D4F18 row[4];
};

extern "C" Vec_001D4F18 func_001522A8(const Mat_001D4F18* m, const Vec_001D4F18* v);

struct Obj_001D4F18 {
    char pad0[0x10];
    Vec_001D4F18 m_pos;
    char pad20[0x40];
    Mat_001D4F18 m_mat;

    void ToLocal(const Seg_001D4F18* in, Seg_001D4F18* out);
};

void Obj_001D4F18::ToLocal(const Seg_001D4F18* in, Seg_001D4F18* out)
{
    *out = *in;
    out->a.f.x -= m_pos.f.x;
    out->a.f.y -= m_pos.f.y;
    out->a.f.z -= m_pos.f.z;
    out->a.f.w -= m_pos.f.w;
    Vec_001D4F18* b = &out->b;
    b->f.x -= m_pos.f.x;
    b->f.y -= m_pos.f.y;
    b->f.z -= m_pos.f.z;
    b->f.w -= m_pos.f.w;
    out->a = func_001522A8(&m_mat, &out->a);
    *b = func_001522A8(&m_mat, b);
}
