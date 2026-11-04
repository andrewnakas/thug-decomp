typedef int qword_001D5340 __attribute__((mode(TI)));

struct Vector_001D5340 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001D5340 q;
    };
    Vector_001D5340() {}
    Vector_001D5340(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

extern "C" float sqrtf(float x);

struct Seg_001D5340 {
    Vector_001D5340 p0;
    Vector_001D5340 p1;
};

struct Box_001D5340 {
    Vector_001D5340 min;
    Vector_001D5340 max;
};

struct Mat_001D5340 {
    Vector_001D5340 r[4];
};

struct Hit_001D5340 {
    Vector_001D5340 normal;
    Vector_001D5340 point;
    int m20;
};

struct Coll_001D5340 {
    char m_pad[0x10];
    Vector_001D5340 m_pos;
    Mat_001D5340 m_mat;
    char m_pad60[0xB0 - 0x60];
    Box_001D5340 m_box;
    bool Overlaps(const Box_001D5340& b) const
    {
        if (m_box.min.x > b.max.x || b.min.x > m_box.max.x || m_box.min.z > b.max.z || b.min.z > m_box.max.z ||
            m_box.min.y > b.max.y || b.min.y > m_box.max.y)
            return false;
        return true;
    }
};

extern "C" void func_00101F38(Seg_001D5340* seg);
extern "C" void func_001D4F18(Coll_001D5340* self, void* line, Seg_001D5340* seg);
extern "C" void func_00102328(Box_001D5340* box, Vector_001D5340* p);
extern "C" void func_00102358(Box_001D5340* box, Vector_001D5340* p);
extern "C" int func_001027F0(Box_001D5340* box, Seg_001D5340* seg, Vector_001D5340* point, Vector_001D5340* normal);
extern "C" Vector_001D5340 func_001522A8(Mat_001D5340* m, Vector_001D5340* v);
extern "C" bool func_001D1EF0(void* line, void* obj, Hit_001D5340* hit, float t, void* data);

static inline Vector_001D5340 Sub_001D5340(const Vector_001D5340& a, const Vector_001D5340& b)
{
    return Vector_001D5340(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vector_001D5340 Xform_001D5340(Mat_001D5340* m, Vector_001D5340& v)
{
    return func_001522A8(m, &v);
}

static inline float Len_001D5340(const Vector_001D5340& v)
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

extern "C" bool func_001D5340(Coll_001D5340* self, void* line, void* obj, void* data)
{
    Seg_001D5340 seg;
    func_00101F38(&seg);
    func_001D4F18(self, line, &seg);
    Box_001D5340 box;
    func_00102328(&box, &seg.p0);
    func_00102358(&box, &seg.p1);
    if (!self->Overlaps(box))
        return false;
    Vector_001D5340 point;
    Vector_001D5340 normal;
    if (!func_001027F0(&self->m_box, &seg, &point, &normal))
        return false;
    float t = Len_001D5340(Sub_001D5340(point, seg.p0)) / Len_001D5340(Sub_001D5340(seg.p1, seg.p0));
    Hit_001D5340 hit;
    point = Xform_001D5340(&self->m_mat, point);
    hit.point = point;
    hit.point.x += self->m_pos.x;
    hit.point.y += self->m_pos.y;
    hit.point.z += self->m_pos.z;
    hit.point.w += self->m_pos.w;
    normal = Xform_001D5340(&self->m_mat, normal);
    hit.normal = normal;
    return func_001D1EF0(line, self, &hit, t, data);
}
