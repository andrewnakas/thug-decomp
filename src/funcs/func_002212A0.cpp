typedef int qword_002212A0 __attribute__((mode(TI)));

struct Vec_002212A0 {
    union {
        qword_002212A0 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

union Row_002212A0 {
    qword_002212A0 q;
    struct {
        float x, y, z, w;
    } f;
};

struct Mat_002212A0 {
    Row_002212A0 r[4];
    Mat_002212A0() {}
    const Row_002212A0& operator[](int i) const { return r[i]; }
    Mat_002212A0(const Mat_002212A0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_002212A0& operator=(const Mat_002212A0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    void Ident()
    {
        r[0].f.x = 1.0f; r[0].f.y = 0.0f; r[0].f.z = 0.0f; r[0].f.w = 0.0f;
        r[1].f.x = 0.0f; r[1].f.y = 1.0f; r[1].f.z = 0.0f; r[1].f.w = 0.0f;
        r[2].f.x = 0.0f; r[2].f.y = 0.0f; r[2].f.z = 1.0f; r[2].f.w = 0.0f;
        r[3].f.x = 0.0f; r[3].f.y = 0.0f; r[3].f.z = 0.0f; r[3].f.w = 1.0f;
    }
};

struct Obj_002212A0 {
    char pad0[0x70];
    Mat_002212A0 m70;
    Row_002212A0 mB0;
};

struct Script_002212A0 {
    char pad0[0x18];
    void* m18;
    char pad1C[0xBC - 0x1C];
    Obj_002212A0* mBC;
};

extern char D_00371880[];
extern char D_00371890[];
extern char D_003718A0[];

extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001E7268(void* params, char* name, int value);
extern "C" void func_003233B8(Row_002212A0* d, Row_002212A0* s);
extern "C" Mat_002212A0* func_00100928(Mat_002212A0* out, float a);
extern "C" void func_00323318(Mat_002212A0* d, Mat_002212A0* a, Mat_002212A0* b);
extern "C" Vec_002212A0 func_00323298(Mat_002212A0* m, Row_002212A0* v);
extern "C" float sqrtf(float);

static inline Mat_002212A0 operator*(const Mat_002212A0& a, const Mat_002212A0& b)
{
    Mat_002212A0 r = b;
    func_00323318(&r, (Mat_002212A0*)&a, &r);
    return r;
}

static inline Vec_002212A0 operator*(const Mat_002212A0& a, const Row_002212A0& b)
{
    Vec_002212A0 r = func_00323298((Mat_002212A0*)&a, (Row_002212A0*)&b);
    return r;
}

extern "C" bool func_002212A0(void* params, Script_002212A0* script)
{
    Obj_002212A0* obj = script->mBC;
    if (obj) {
        Row_002212A0 v = obj->mB0;
        float scale = 1.0f;
        float angle = 0.0f;
        float x = v.f.x;
        float y = v.f.y;
        float z = v.f.z;
        func_001E7EB0(params, 0x5582FE27, &angle, 0);
        func_001E7200(script->m18, 0x6187906D, (int)x);
        func_001E7200(script->m18, 0x1680A0FB, (int)y);
        func_001E7200(script->m18, 0x8F89F141, (int)z);
        func_001E7EB0(params, 0x13B9DA7B, &scale, 0);
        v.f.y = 0.0f;
        if (sqrtf(v.f.x * v.f.x + v.f.z * v.f.z) > 100.0f) {
            func_003233B8(&v, &v);
            if (angle != 0.0f) {
                Mat_002212A0 m;
                m.Ident();
                {
                    Mat_002212A0 rot;
                    func_00323318(&m, func_00100928(&rot, angle * 0.017453294f), &m);
                }
                v.q = (m * v).q;
            }
            func_001E7268(script->m18, D_00371880, (int)(v.f.x * scale));
            func_001E7268(script->m18, D_00371890, (int)(v.f.y * scale));
            func_001E7268(script->m18, D_003718A0, (int)(v.f.z * scale));
            return true;
        }
        Row_002212A0 dir = obj->m70.r[2];
        if (angle != 0.0f) {
            Mat_002212A0 m = obj->m70;
            m = m * *func_00100928((Mat_002212A0*)0x70003FC0, angle * 0.017453294f);
            dir = m.r[2];
        }
        func_001E7200(script->m18, 0xBDED7A76, (int)(dir.f.x * scale));
        func_001E7200(script->m18, 0xCAEA4AE0, (int)(dir.f.y * scale));
        func_001E7200(script->m18, 0x53E31B5A, (int)(dir.f.z * scale));
        return true;
    }
    return false;
}
