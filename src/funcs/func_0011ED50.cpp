typedef int qword __attribute__((mode(TI)));

struct Vec_0011ED50 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Quat_0011ED50 {
    float x, y, z, w;
    Quat_0011ED50(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void Conj() { x = -x; y = -y; z = -z; }
};

extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern void* D_00388A70;

struct Mat_0011ED50;
extern "C" void func_00323318(Mat_0011ED50* d, Mat_0011ED50* a, Mat_0011ED50* b);

struct Mat_0011ED50 {
    Vec_0011ED50 r[4];
    Mat_0011ED50() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    const Vec_0011ED50& operator[](int i) const { return r[i]; }
    Mat_0011ED50(const Mat_0011ED50& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    void InvertOrtho()
    {
        Vec_0011ED50 t = r[3];
        r[3].x = -(t.x * r[0].x + t.y * r[0].y + t.z * r[0].z);
        r[3].y = -(t.x * r[1].x + t.y * r[1].y + t.z * r[1].z);
        r[3].z = -(t.x * r[2].x + t.y * r[2].y + t.z * r[2].z);
        float s;
        s = r[0].y; r[0].y = r[1].x; r[1].x = s;
        s = r[0].z; r[0].z = r[2].x; r[2].x = s;
        s = r[1].z; r[1].z = r[2].y; r[2].y = s;
    }
    void FromQuat(const Quat_0011ED50& q)
    {
        Vec_0011ED50 sq;
        Vec_0011ED50 c;
        Vec_0011ED50 w;
        sq.x = q.x * q.x;
        sq.y = q.y * q.y;
        sq.z = q.z * q.z;
        c.x = q.y * q.z;
        c.y = q.z * q.x;
        c.z = q.x * q.y;
        w.x = q.w * q.x;
        w.y = q.w * q.y;
        w.z = q.w * q.z;
        r[0].x = 1.0f - (sq.y + sq.z + (sq.y + sq.z));
        r[0].y = (c.z + w.z) + (c.z + w.z);
        r[0].z = (c.y - w.y) + (c.y - w.y);
        r[0].w = 0.0f;
        r[1].x = (c.z - w.z) + (c.z - w.z);
        r[1].y = 1.0f - (sq.x + sq.z + (sq.x + sq.z));
        r[1].z = (c.x + w.x) + (c.x + w.x);
        r[1].w = 0.0f;
        r[2].x = (c.y + w.y) + (c.y + w.y);
        r[2].y = (c.x - w.x) + (c.x - w.x);
        r[2].z = 1.0f - (sq.x + sq.y + (sq.x + sq.y));
        r[2].w = 0.0f;
    }
};

extern "C" void* func_00331404(void*, const void*, unsigned int);

struct C_0011ED50 {
    int m0;
    int m_count;
    int m_ids[64];
    int m_parents[64];
    int m_third[64];
    char pad[0x48C - 0x308];
    Mat_0011ED50* m_mats;
    int m_490;
    int Load(int* data);
};

extern "C" int func_0011F4C0(C_0011ED50* self, int i);
extern "C" int func_0011F508(C_0011ED50* self, int id);

int C_0011ED50::Load(int* data)
{
    int* p = data;
    p++;
    m_490 = *p;
    p++;
    m_count = *p;
    p++;
    func_00331404(m_ids, p, m_count * 4);
    p += m_count;
    func_00331404(m_parents, p, m_count * 4);
    p += m_count;
    func_00331404(m_third, p, m_count * 4);
    p += m_count;
    m_mats = new Mat_0011ED50[m_count];
    for (int i = 0; i < m_count; i++) {
        Quat_0011ED50 q(((float*)p)[0], ((float*)p)[1], ((float*)p)[2], ((float*)p)[3]);
        p += 4;
        Vec_0011ED50 pos;
        pos.x = ((float*)p)[0];
        pos.y = ((float*)p)[1];
        pos.z = ((float*)p)[2];
        pos.w = ((float*)p)[3];
        p += 4;
        q.Conj();
        Mat_0011ED50 m;
        m.FromQuat(q);
        m.r[3] = pos;
        m.r[3].w = 1.0f;
        if (i) {
            Mat_0011ED50 par = m_mats[func_0011F508(this, func_0011F4C0(this, i))];
            par.InvertOrtho();
            Mat_0011ED50* pm = &m;
            func_00323318(pm, &par, pm);
            m.r[0].w = 0.0f;
            m.r[1].w = 0.0f;
            m.r[2].w = 0.0f;
            m.r[3].w = 1.0f;
        }
        m.InvertOrtho();
        m_mats[i] = m;
    }
    return 1;
}
