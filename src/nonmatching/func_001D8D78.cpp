/* fuzzy: 95.1 */
extern "C" float fabsf(float x);
typedef unsigned int u128_001D8D78 __attribute__((mode(TI)));

struct Vec_001D8D78 {
    union {
        struct {
            float x, y, z, w;
        } f;
        u128_001D8D78 q;
    } u;
    Vec_001D8D78() {}
    Vec_001D8D78(float x, float y, float z, float w)
    {
        u.f.x = x;
        u.f.y = y;
        u.f.z = z;
        u.f.w = w;
    }
    Vec_001D8D78(const Vec_001D8D78& o) { u.q = o.u.q; }
    Vec_001D8D78& operator=(const Vec_001D8D78& o)
    {
        u.q = o.u.q;
        return *this;
    }
};

struct Idx3_001D8D78 {
    int v[3];
};

struct Face_001D8D78 {
    unsigned short m_flags;
    unsigned short m_2;
};

struct SmallFace_001D8D78 {
    unsigned short m_flags;
    unsigned short m_2;
    unsigned char idx[3];
    char m_pad7;
};

struct BigFace_001D8D78 {
    unsigned short m_flags;
    unsigned short m_2;
    unsigned short idx[3];
};

struct PackedVert_001D8D78 {
    unsigned short x, y, z;
};

struct RawVert_001D8D78 {
    float x, y, z;
};

struct Mesh_001D8D78 {
    int m_name;
    int m4;
    unsigned short m_numFaces;
    unsigned char m_smallFaces;
    unsigned char m_packed;
    void* m_faces;
    Vec_001D8D78 m_origin;
    char m_pad20[0x10];
    void* m_verts;

    Face_001D8D78* GetFace(int f)
    {
        if (m_smallFaces)
            return (Face_001D8D78*)&((SmallFace_001D8D78*)m_faces)[f];
        return (Face_001D8D78*)&((BigFace_001D8D78*)m_faces)[f];
    }
    unsigned short GetIndex(int f, int k)
    {
        int idx;
        if (m_smallFaces)
            idx = ((SmallFace_001D8D78*)m_faces)[f].idx[k];
        else
            idx = ((BigFace_001D8D78*)m_faces)[f].idx[k];
        return idx;
    }
    Vec_001D8D78 GetPackedVert(int v)
    {
        Vec_001D8D78 r = m_origin;
        PackedVert_001D8D78* p = (PackedVert_001D8D78*)m_verts;
        r.u.f.x += p[v].x * 0.0625f;
        r.u.f.y += p[v].y * 0.0625f;
        r.u.f.z += p[v].z * 0.0625f;
        r.u.f.w = 0.0f;
        return r;
    }
    Vec_001D8D78 GetRawVert(int v)
    {
        Vec_001D8D78 r;
        RawVert_001D8D78* p = (RawVert_001D8D78*)m_verts;
        r.u.f.x = p[v].x;
        r.u.f.y = p[v].y;
        r.u.f.z = p[v].z;
        r.u.f.w = 0.0f;
        return r;
    }
    Vec_001D8D78 GetVert(int v)
    {
        if (m_packed)
            return GetPackedVert(v);
        return GetRawVert(v);
    }
};

extern "C" void func_003233B8(Vec_001D8D78* d, Vec_001D8D78* s);
extern "C" void func_00132058(int n, Vec_001D8D78* pts, int name);
extern const Idx3_001D8D78 D_00364380;

static inline Vec_001D8D78 Sub_001D8D78(const Vec_001D8D78& a, const Vec_001D8D78& b)
{
    return Vec_001D8D78(a.u.f.x - b.u.f.x, a.u.f.y - b.u.f.y, a.u.f.z - b.u.f.z, a.u.f.w - b.u.f.w);
}

static inline Vec_001D8D78 Cross_001D8D78(const Vec_001D8D78& a, const Vec_001D8D78& b)
{
    return Vec_001D8D78(a.u.f.y * b.u.f.z - a.u.f.z * b.u.f.y, a.u.f.z * b.u.f.x - a.u.f.x * b.u.f.z,
                        a.u.f.x * b.u.f.y - a.u.f.y * b.u.f.x, 0.0f);
}

extern "C" void func_001D8D78(Mesh_001D8D78* m)
{
    for (int i = 0; i < m->m_numFaces - 1; i++) {
        Vec_001D8D78 pts[4];
        pts[0] = m->GetVert(m->GetIndex(i, 0));
        pts[1] = m->GetVert(m->GetIndex(i, 1));
        pts[2] = m->GetVert(m->GetIndex(i, 2));
        for (int j = i + 1; j < m->m_numFaces; j++) {
            pts[0] = m->GetVert(m->GetIndex(j, 0));
            pts[1] = m->GetVert(m->GetIndex(j, 1));
            pts[2] = m->GetVert(m->GetIndex(j, 2));
            int count = 0;
            Idx3_001D8D78 si = D_00364380;
            Idx3_001D8D78 sj = D_00364380;
            for (int k = 0; k < 3; k++) {
                if (m->GetIndex(i, k) == m->GetIndex(j, 0)) {
                    si.v[k] = m->GetIndex(i, k);
                    sj.v[0] = m->GetIndex(j, 0);
                    count++;
                } else if (m->GetIndex(i, k) == m->GetIndex(j, 1)) {
                    si.v[k] = m->GetIndex(i, k);
                    sj.v[1] = m->GetIndex(j, 1);
                    count++;
                } else if (m->GetIndex(i, k) == m->GetIndex(j, 2)) {
                    si.v[k] = m->GetIndex(i, k);
                    sj.v[2] = m->GetIndex(j, 2);
                    count++;
                }
            }
            if (count != 2)
                continue;
            pts[0] = m->GetVert(m->GetIndex(i, 0));
            pts[1] = m->GetVert(m->GetIndex(i, 1));
            pts[2] = m->GetVert(m->GetIndex(i, 2));
            Vec_001D8D78 na = Cross_001D8D78(Sub_001D8D78(pts[1], pts[0]), Sub_001D8D78(pts[2], pts[0]));
            pts[0] = m->GetVert(m->GetIndex(j, 0));
            pts[1] = m->GetVert(m->GetIndex(j, 1));
            pts[2] = m->GetVert(m->GetIndex(j, 2));
            Vec_001D8D78 nb = Cross_001D8D78(Sub_001D8D78(pts[1], pts[0]), Sub_001D8D78(pts[2], pts[0]));
            func_003233B8(&na, &na);
            func_003233B8(&nb, &nb);
            if (fabsf(nb.u.f.x - na.u.f.x) <= 0.05f && fabsf(nb.u.f.y - na.u.f.y) <= 0.05f &&
                fabsf(nb.u.f.z - na.u.f.z) <= 0.05f) {
                int other = -1;
                for (int k = 0; k < 3; k++) {
                    if (sj.v[k] == -1) {
                        other = m->GetIndex(j, k);
                        break;
                    }
                }
                if (si.v[0] >= 0 && si.v[1] >= 0) {
                    pts[0] = m->GetVert(m->GetIndex(i, 0));
                    pts[1] = m->GetVert(other);
                    pts[2] = m->GetVert(m->GetIndex(i, 1));
                    pts[3] = m->GetVert(m->GetIndex(i, 2));
                } else if (si.v[1] >= 0 && si.v[2] >= 0) {
                    pts[0] = m->GetVert(m->GetIndex(i, 0));
                    pts[1] = m->GetVert(m->GetIndex(i, 1));
                    pts[2] = m->GetVert(other);
                    pts[3] = m->GetVert(m->GetIndex(i, 2));
                } else if (si.v[0] >= 0 && si.v[2] >= 0) {
                    pts[0] = m->GetVert(m->GetIndex(i, 0));
                    pts[1] = m->GetVert(m->GetIndex(i, 1));
                    pts[2] = m->GetVert(m->GetIndex(i, 2));
                    pts[3] = m->GetVert(other);
                }
                func_00132058(4, pts, m->m_name);
                break;
            }
        }
    }
}
