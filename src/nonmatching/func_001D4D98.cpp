/* fuzzy: 96.7 */
typedef int qword_001D4D98 __attribute__((mode(TI)));

struct Vec_001D4D98 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001D4D98 q;
    };
    Vec_001D4D98() {}
    Vec_001D4D98(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_001D4D98& operator+=(const Vec_001D4D98& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

static inline Vec_001D4D98 operator+(const Vec_001D4D98& a, const Vec_001D4D98& b)
{
    Vec_001D4D98 r = a;
    r += b;
    return r;
}

struct Mat_001D4D98 {
    Vec_001D4D98 row[4];
};

struct Short3_001D4D98 {
    unsigned short x, y, z;
};

struct Float3_001D4D98 {
    float x, y, z;
};

struct Mesh_001D4D98 {
    char pad0[0xB];
    unsigned char m_packed;
    char padC[4];
    Vec_001D4D98 m_offset;
    char pad20[0x10];
    void* m_verts;
};

extern "C" Vec_001D4D98* func_001522A8(Vec_001D4D98* out, Mat_001D4D98* m, Vec_001D4D98* v);

static inline void Rotate_001D4D98(Vec_001D4D98* v, Mat_001D4D98* m, Vec_001D4D98* scratch)
{
    scratch->q = v->q;
    scratch->w = 0.0f;
    func_001522A8(v, m, scratch);
}

struct Inst_001D4D98 {
    char pad0[0x8];
    Mesh_001D4D98* m_mesh;
    char padC[4];
    Vec_001D4D98 m_pos;
    Mat_001D4D98 m_mat;
    Vec_001D4D98 GetVertex(int idx);
};

Vec_001D4D98 Inst_001D4D98::GetVertex(int idx)
{
    Mesh_001D4D98* m = m_mesh;
    Vec_001D4D98 r;
    Vec_001D4D98 v;
    if (m->m_packed) {
        v.q = m->m_offset.q;
        v.x += ((Short3_001D4D98*)m->m_verts)[idx].x * 0.0625f;
        v.y += ((Short3_001D4D98*)m->m_verts)[idx].y * 0.0625f;
        v.z += ((Short3_001D4D98*)m->m_verts)[idx].z * 0.0625f;
        v.w = 0.0f;
    } else {
        v.x = ((Float3_001D4D98*)m->m_verts)[idx].x;
        v.y = ((Float3_001D4D98*)m->m_verts)[idx].y;
        v.z = ((Float3_001D4D98*)m->m_verts)[idx].z;
        v.w = 0.0f;
    }
    Rotate_001D4D98(&v, &m_mat, &r);
    r.q = v.q;
    r.x += m_pos.x;
    r.y += m_pos.y;
    r.z += m_pos.z;
    r.w += m_pos.w;
    return r;
}
