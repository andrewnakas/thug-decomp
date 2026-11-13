/* cflags: -fno-gcse */
/* fuzzy: 97.9 */
/* sym: __13Desc_001BC938 = 0x00141910 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001BC938 {
    union {
        qword q;
        float c[4];
        struct { float x, y, z, w; };
    };
    void Set(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
    Vec_001BC938& operator=(const Vec_001BC938& o) { q = o.q; return *this; }
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    void operator*=(float k) { c[0] *= k; c[1] *= k; c[2] *= k; c[3] *= k; }
    bool operator==(const Vec_001BC938& o) const
    {
        return x == o.x && y == o.y && z == o.z && w == o.w;
    }
};

struct VecC_001BC938 : Vec_001BC938 {
    VecC_001BC938(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
};

struct Mat_001BC938 {
    Vec_001BC938 r[4];
    Vec_001BC938& operator[](int i) { return r[i]; }
    void Ident()
    {
        r[0].x = 1.0f; r[0].y = 0.0f; r[0].z = 0.0f; r[0].w = 0.0f;
        r[1].x = 0.0f; r[1].y = 1.0f; r[1].z = 0.0f; r[1].w = 0.0f;
        r[2].x = 0.0f; r[2].y = 0.0f; r[2].z = 1.0f; r[2].w = 0.0f;
        r[3].x = 0.0f; r[3].y = 0.0f; r[3].z = 0.0f; r[3].w = 1.0f;
    }
};

static inline VecC_001BC938 Cross_001BC938(const Vec_001BC938& a, const Vec_001BC938& b)
{
    return VecC_001BC938(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

extern "C" void func_00323298(Vec_001BC938* out, const Mat_001BC938* m, const Vec_001BC938* v);
static inline Vec_001BC938 Xform_001BC938(const Mat_001BC938& m, const Vec_001BC938& v)
{
    Vec_001BC938 r;
    func_00323298(&r, &m, &v);
    return r;
}

struct Desc_001BC938 {
    Desc_001BC938();
    int m_0;
    unsigned int m_4;
    int m_8;
    float m_C, m_10, m_14;
    float m_18, m_1C, m_20;
    int m_24;
    float m_28, m_2C, m_30;
    Mat_001BC938 m_40;
    Vec_001BC938 m_80[3];
    Vec_001BC938 m_B0[3];
    int m_E0;
    Vec_001BC938 m_F0[3];
    int m_120;
    /* Equivalence fix, proven by the game's instructions: desc is at sp+0 (func_00142708 gets `daddu $a1, $sp, $zero`
       at 0x001BD390) and the fields after m_120 sit at 0x128.., not 0x124..: `sw $v0, 0x120($sp)` (0x001BD02C),
       `sb $v0, 0x128($sp)` .. `sb $v0, 0x133($sp)` (0x001BD070-0x001BD1CC), `addiu $a2, $sp, 0x134/0x13C/0x138/0x140/
       0x144/0x148/0x14C` for the param reads (0x001BD1D4-0x001BD264). Hence the 4-byte m_124 gap. */
    int m_124;
    unsigned char m_128[12];
    unsigned int m_134;
    int m_138;
    int m_13C;
    unsigned int m_140;
    int m_144;
    int m_148;
    int m_14C;
    int m_150[3];
};

extern "C" bool func_001E8398(void* params, unsigned int name, void* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8918(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_001BC938* out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, void** out, int required);
extern "C" int func_001E9270(void* arr, int i);
extern "C" int func_0010FC30();
extern "C" void func_003233B8(Vec_001BC938* out, Vec_001BC938* in);
extern "C" Mat_001BC938* func_00100890(Mat_001BC938* out, float a);
extern "C" Mat_001BC938* func_00100928(Mat_001BC938* out, float a);
extern "C" Mat_001BC938* func_001009C0(Mat_001BC938* out, float a);
extern "C" void func_00323318(Mat_001BC938* a, Mat_001BC938* b, Mat_001BC938* c);
extern "C" void* func_00142708(void* mgr, Desc_001BC938* d, int now);
extern void* D_00389C34;

struct Obj_001BC938 {
    char pad[0x1C];
    unsigned int m_1C;
    void* m_20;
    char pad2[0x8];
    int m_2C;
    void Spawn(void* params);
};

void Obj_001BC938::Spawn(void* params)
{
    Desc_001BC938 desc;
    Vec_001BC938 ang;
    int now = 0;
    float scale = 1.0f;
    func_001E8398(params, 0x092276DB, &m_1C, 0);
    func_001E7DE8(params, 0x5A235299, &m_2C, 0);
    if (func_001E8708(params, 0x18C671F0)) {
        now = 1;
        desc.m_0 = func_0010FC30();
    } else {
        func_001E8398(params, 0xA1DC81F9, &desc.m_0, 0);
    }
    func_001E8398(params, 0x7321A8D6, &desc.m_4, 0);
    desc.m_8 = func_001E8708(params, 0xA7A5BFFB);
    func_001E8918(params, 0x13B9DA7B, &scale, 0);
    func_001E7EB0(params, 0x3BEE67C8, &desc.m_C, 0);
    func_001E7EB0(params, 0x8E39913D, &desc.m_10, 0);
    func_001E7EB0(params, 0x3F243A3C, &desc.m_14, 0);

    Mat_001BC938 rot;
    rot.Ident();
    if (func_001E8708(params, 0x7045843A)) {
        Vec_001BC938 dir;
        func_001E7FA8(params, 0x0C4C809E, &dir, 1);
        func_003233B8(&dir, &dir);
        rot.r[2] = dir;
        if (rot[2] == VecC_001BC938(0.0f, 1.0f, 0.0f, 1.0f)) {
            rot.r[0] = Cross_001BC938(dir, VecC_001BC938(0.0f, 0.0f, -1.0f, 1.0f));
        } else {
            rot.r[0] = Cross_001BC938(dir, VecC_001BC938(0.0f, 1.0f, 0.0f, 1.0f));
        }
        rot.r[1] = Cross_001BC938(rot.r[2], rot.r[0]);
    }
    desc.m_C *= scale;
    desc.m_10 *= scale;
    desc.m_14 *= scale;
    func_001E7EB0(params, 0x05400A25, &desc.m_18, 0);
    func_001E7EB0(params, 0xFF7D9AA9, &desc.m_1C, 0);
    func_001E7EB0(params, 0x5539FCEE, &desc.m_20, 0);
    desc.m_18 *= scale;
    desc.m_1C *= scale;
    desc.m_20 *= scale;
    func_001E7DE8(params, 0x9E52A20F, &desc.m_24, 0);
    func_001E7EB0(params, 0x35B65BD4, &desc.m_28, 0);
    func_001E7EB0(params, 0xC218CF77, &desc.m_2C, 0);
    func_001E7EB0(params, 0x520682C6, &desc.m_30, 0);
    if (func_001E8708(params, 0x64F194ED)) {
        func_001E7FA8(params, 0x3D5EA6A4, &desc.m_80[0], 0);
    } else {
        func_001E7FA8(params, 0x7F261953, &desc.m_80[0], 0);
    }
    func_001E7FA8(params, 0x004B51A2, &desc.m_80[1], 0);
    func_001E7FA8(params, 0x5854AB9E, &desc.m_80[2], 0);
    desc.m_80[0] *= scale;
    desc.m_80[1] *= scale;
    desc.m_80[2] *= scale;
    desc.m_80[0] = Xform_001BC938(rot, desc.m_80[0]);
    desc.m_80[1] = Xform_001BC938(rot, desc.m_80[1]);
    desc.m_80[2] = Xform_001BC938(rot, desc.m_80[2]);
    func_001E7FA8(params, 0x9656F775, &desc.m_B0[0], 0);
    func_001E7FA8(params, 0xC3CD20A2, &desc.m_B0[1], 0);
    func_001E7FA8(params, 0x829FE7DD, &desc.m_B0[2], 0);
    desc.m_B0[0] *= scale;
    desc.m_B0[1] *= scale;
    desc.m_B0[2] *= scale;
    desc.m_B0[0] = Xform_001BC938(rot, desc.m_B0[0]);
    desc.m_B0[1] = Xform_001BC938(rot, desc.m_B0[1]);
    desc.m_B0[2] = Xform_001BC938(rot, desc.m_B0[2]);
    desc.m_120 = func_001E8708(params, 0x454962EF);
    func_001E7EB0(params, 0x59463C93, &desc.m_30, 0);

    void* arr;
    int v;
    if (func_001E8248(params, 0xDAB75B6C, &arr, 0)) {
        v = func_001E9270(arr, 0); desc.m_128[0] = v;
        v = func_001E9270(arr, 1); desc.m_128[1] = v;
        v = func_001E9270(arr, 2); desc.m_128[2] = v;
    }
    if (func_001E8248(params, 0x0444769A, &arr, 0)) {
        v = func_001E9270(arr, 0); desc.m_128[4] = v;
        v = func_001E9270(arr, 1); desc.m_128[5] = v;
        v = func_001E9270(arr, 2); desc.m_128[6] = v;
    }
    if (func_001E8248(params, 0x5A3728E7, &arr, 0)) {
        v = func_001E9270(arr, 0); desc.m_128[8] = v;
        v = func_001E9270(arr, 1); desc.m_128[9] = v;
        v = func_001E9270(arr, 2); desc.m_128[10] = v;
    }
    if (func_001E7DE8(params, 0x4D83DB4C, &v, 0)) desc.m_128[3] = v;
    if (func_001E7DE8(params, 0x4ABA1FF1, &v, 0)) desc.m_128[7] = v;
    if (func_001E7DE8(params, 0x5CF83ACA, &v, 0)) desc.m_128[11] = v;
    func_001E8398(params, 0xDD6BB3D5, &desc.m_134, 0);
    func_001E7DE8(params, 0x9F677D4E, &desc.m_13C, 0);
    func_001E7DE8(params, 0x13D0BE1D, &desc.m_138, 0);
    func_001E8398(params, 0x7D99F28D, &desc.m_140, 0);
    func_001E7DE8(params, 0x4EEDFAE7, &desc.m_144, 0);
    func_001E7DE8(params, 0xD7E4AB5D, &desc.m_148, 0);
    func_001E7DE8(params, 0xE4279BA2, &desc.m_14C, 0);

    desc.m_40.Ident();
    ang.Set(0.0f, 0.0f, 0.0f, 1.0f);
    func_001E7FA8(params, 0x9D2D0915, &ang, 0);
    Mat_001BC938 t;
    func_00323318(&desc.m_40, func_00100890(&t, ang[0]), &desc.m_40);
    func_00323318(&desc.m_40, func_00100928(&t, ang[1]), &desc.m_40);
    func_00323318(&desc.m_40, func_001009C0(&t, ang[2]), &desc.m_40);
    desc.m_E0 = func_001E8708(params, 0xB7B7240D);
    if (desc.m_E0) {
        for (int i = 0; i < 3; i++) desc.m_F0[i] = desc.m_80[i];
    }
    m_20 = func_00142708(D_00389C34, &desc, now);
}
