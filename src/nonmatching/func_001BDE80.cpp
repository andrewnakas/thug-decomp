/* fuzzy: 97.6 */
/* sym: __15Feeler_001BDE80 = 0x00209240 */
/* sym: SetStart__15Feeler_001BDE80RC12Vec_001BDE80 = 0x00209360 */
/* sym: SetEnd__15Feeler_001BDE80RC12Vec_001BDE80 = 0x00209370 */
/* sym: GetCollision__15Feeler_001BDE80ii = 0x002093E8 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001BDE80 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001BDE80() {}
    Vec_001BDE80(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001BDE80& operator+=(const Vec_001BDE80& v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
};

inline Vec_001BDE80 operator*(const Vec_001BDE80& a, float s)
{
    return Vec_001BDE80(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" int func_002A19A8(void* net);
extern "C" int func_001A9E60(int id);
extern "C" unsigned int func_0010FC30();
extern "C" void func_003233B8(Vec_001BDE80* dst, const Vec_001BDE80* src);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_0029E1F0(void* comp);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7528(void* s, unsigned int name, const Vec_001BDE80* v);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_001F0210(unsigned int script, void* params, int a, int b, int c);
extern "C" void func_001E6AE8(void* s, int flags);
extern void* D_00392068;

struct Ref_001BDE80 {
    void* m_obj;
    ~Ref_001BDE80()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

struct Feeler_001BDE80 {
    int m0[40];
    Vec_001BDE80 mA0;
    int mB0[4];
    Ref_001BDE80 mC0;
    int mC4[7];
    Feeler_001BDE80();
    void SetStart(const Vec_001BDE80& v);
    void SetEnd(const Vec_001BDE80& v);
    int GetCollision(int a, int b);
};

struct Obj_001BDE80 {
    int m_pad[20];
    Vec_001BDE80 m50;
    int m60[20];
    Vec_001BDE80 mB0;
};

extern "C" void func_00184950(Obj_001BDE80* obj);

struct C_001BDE80 {
    int m_pad[3];
    Obj_001BDE80* mC;
    int m10[3];
    int m1C;
    float m20;
    float m24;
    unsigned int m28;
    unsigned int m2C;
    unsigned int m30;
    int m34;
    int m38;
    int m3C;
    Vec_001BDE80 m40;
    Vec_001BDE80 m50;
    void Update();
};

void C_001BDE80::Update()
{
    if (!func_002A19A8(D_00392068) && func_001A9E60(m1C)) return;
    if (func_0010FC30() - m28 > 10000) {
        func_00184950(mC);
    } else if (m34) {
        if (m30 < func_0010FC30()) func_00184950(mC);
    } else {
        Vec_001BDE80 dir;
        Vec_001BDE80 start;
        Vec_001BDE80 end;
        Feeler_001BDE80 f;
        dir = mC->mB0;
        func_003233B8(&dir, &dir);
        if (m38)
            start = mC->m50;
        else
            start = m50;
        start.y += 24.0f;
        end = mC->m50;
        end.y += 24.0f;
        end += dir * m20;
        f.SetStart(start);
        f.SetEnd(end);
        if (f.GetCollision(1, 0) && !m34) {
            void* comp = func_00185578(mC, 0x7767D6D7);
            if (comp) func_0029E1F0(comp);
            m34 = 1;
            m30 = func_0010FC30() + 1000;
            if (m2C) {
                Vec_001BDE80 pt = f.mA0;
                void* s = func_001E6978(func_001190D0(8));
                Vec_001BDE80 p = pt;
                func_001E7528(s, 0x7F261953, &p);
                p = m40;
                func_001E7528(s, 0x0C4C809E, &p);
                func_001E72B0(s, 0x13B9DA7B, m24);
                func_001F0210(m2C, s, 0, 0, 0);
                if (s) func_001E6AE8(s, 3);
            }
        }
    }
    m50 = mC->m50;
    m38 = 0;
}
