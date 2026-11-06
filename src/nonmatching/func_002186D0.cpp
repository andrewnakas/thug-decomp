/* fuzzy: 83.3 */
typedef int qword_002186D0 __attribute__((mode(TI)));

union Row_002186D0 {
    qword_002186D0 q;
    struct {
        float x, y, z, w;
    } f;
};

struct Mat_002186D0 {
    Row_002186D0 r[4];
    Mat_002186D0() {}
    const Row_002186D0& operator[](int i) const { return r[i]; }
    Mat_002186D0(const Mat_002186D0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    void Ident()
    {
        r[0].f.x = 1.0f; r[0].f.y = 0.0f; r[0].f.z = 0.0f; r[0].f.w = 0.0f;
        r[1].f.x = 0.0f; r[1].f.y = 1.0f; r[1].f.z = 0.0f; r[1].f.w = 0.0f;
        r[2].f.x = 0.0f; r[2].f.y = 0.0f; r[2].f.z = 1.0f; r[2].f.w = 0.0f;
        r[3].f.x = 0.0f; r[3].f.y = 0.0f; r[3].f.z = 0.0f; r[3].f.w = 1.0f;
    }
};

struct Script_002186D0 {
    char m_pad[0x18];
    void* m_params;
};

extern char D_0038F410[];
extern char D_0038F418[];
extern char D_0038F420[];
extern char D_0038F6C8[];
extern char D_0038F6D0[];
extern char D_0038F6D8[];

extern "C" int func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" int func_001E7318(void* params, const char* name, float v);
extern "C" Mat_002186D0* func_00100890(Mat_002186D0* out, float a);
extern "C" Mat_002186D0* func_00100928(Mat_002186D0* out, float a);
extern "C" Mat_002186D0* func_001009C0(Mat_002186D0* out, float a);
extern "C" void func_00323318(Mat_002186D0* dst, const Mat_002186D0* a, const Mat_002186D0* b);
extern "C" Row_002186D0 func_00323298(Mat_002186D0* m, Row_002186D0* v);

static inline Mat_002186D0 operator*(const Mat_002186D0& a, const Mat_002186D0& b)
{
    Mat_002186D0 r = b;
    func_00323318(&r, &a, &r);
    return r;
}

static inline Row_002186D0 operator*(Mat_002186D0& m, Row_002186D0& v)
{
    Row_002186D0 r = func_00323298(&m, &v);
    return r;
}

extern "C" bool func_002186D0(void* params, Script_002186D0* script)
{
    Row_002186D0 v;
    func_001E7F50(params, D_0038F410, &v.f.x, 1);
    func_001E7F50(params, D_0038F418, &v.f.y, 1);
    func_001E7F50(params, D_0038F420, &v.f.z, 1);
    v.f.w = 1.0f;
    float rx = 0.0f;
    float ry = 0.0f;
    float rz = 0.0f;
    func_001E7F50(params, D_0038F6C8, &rx, 0);
    func_001E7F50(params, D_0038F6D0, &ry, 0);
    func_001E7F50(params, D_0038F6D8, &rz, 0);
    Mat_002186D0 m;
    m.Ident();
    {
        Mat_002186D0 tmp;
        m = m * *func_00100890(&tmp, rx * 0.01745329425f);
    }
    m = m * *func_00100928((Mat_002186D0*)0x70003FC0, ry * 0.01745329425f);
    {
        Mat_002186D0 tmp;
        m = m * *func_001009C0(&tmp, rz * 0.01745329425f);
    }
    v = m * v;
    func_001E7318(script->m_params, D_0038F410, v.f.x);
    func_001E7318(script->m_params, D_0038F418, v.f.y);
    func_001E7318(script->m_params, D_0038F420, v.f.z);
    return true;
}
