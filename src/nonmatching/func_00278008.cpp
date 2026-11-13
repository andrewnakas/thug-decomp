/* fuzzy: 85.8 */
/* sym: __14Range_00278008 = 0x001E4C80 */
typedef int qword __attribute__((mode(TI)));

union Vec_00278008 {
    qword q;
    struct {
        float x, y, z, w;
    };
    float c[4];
    Vec_00278008() {}
    const float& operator[](int i) const { return c[i]; }
    Vec_00278008& operator=(const Vec_00278008& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        w = o.w;
        return *this;
    }
    Vec_00278008(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

static inline Vec_00278008 Cross_00278008(const Vec_00278008& a, const Vec_00278008& b)
{
    Vec_00278008 r;
    r.x = a[1] * b[2] - a[2] * b[1];
    r.y = a[2] * b[0] - a[0] * b[2];
    r.z = a[0] * b[1] - a[1] * b[0];
    r.w = 0.0f;
    return r;
}

union Vec2_00278008 {
    qword q;
    float c[4];
};

struct Range_00278008 {
    int m0;
    float a;
    float b;
    int mC;
    Range_00278008();
};

struct Obj_00278008 {
    char pad0[0x90];
    Vec_00278008 m90;
    char padA0[0x10];
    Vec_00278008 mB0;
};

struct Ref_00278008 {
    char pad0[0x80];
    Vec_00278008 m80;
};

struct Script_00278008 {
    char pad0[0x18];
    void* m_params;
};

extern "C" Vec_00278008* func_00101730(Vec_00278008* v, const Vec_00278008* n);
extern "C" int func_00101C70(const Vec_00278008* a, const Vec_00278008* b, float angle);
extern "C" float func_00101BC8(const Vec_00278008* a, const Vec_00278008* b);
extern "C" int func_001E8998(void* params, unsigned int id, Range_00278008* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" float func_00340F60(float a);
extern "C" void func_001E72B0(void* p, unsigned int key, float v);

class Comp_00278008 {
public:
    char pad0[0xC];
    Obj_00278008* m_obj;
    char pad10[0x10];
    Vec_00278008 m20;
    Vec_00278008 m30;
    Vec_00278008 m40;
    char pad50[0x10];
    float m60;
    Ref_00278008* m64;
    int CallMember(unsigned int name, void* params, Script_00278008* script);
};

int Comp_00278008::CallMember(unsigned int name, void* params, Script_00278008* script)
{
    switch (name) {
    case 0xB992F3CC: {
        Range_00278008 r;
        func_001E8998(params, 0, &r, 1);
        Vec_00278008 v;
        v.q = m_obj->mB0.q;
        func_00101730(&v, &m30);
        return (func_00101C70(&v, &m40, r.a) && !func_00101C70(&v, &m40, r.b)) ? 1 : 0;
    }
    case 0xA745C080: {
        Vec_00278008 v;
        v.q = m_obj->mB0.q;
        func_00101730(&v, &m30);
        const Vec_00278008& c = Cross_00278008(v, m40);
        return c.w < c.y;
    }
    case 0xC8C4D2F4: {
        Vec_00278008 v;
        v.q = m_obj->mB0.q;
        func_00101730(&v, &m30);
        Vec_00278008 c;
        c.x = v.y * m40.z - v.z * m40.y;
        c.y = v.z * m40.x - v.x * m40.z;
        c.z = v.x * m40.y - v.y * m40.x;
        c.w = 0.0f;
        return c.y < c.w;
    }
    case 0xA0551543: {
        float f = 0.0f;
        func_001E7EB0(params, 0, &f, 1);
        float d = m30.x * m64->m80.x + m30.y * m64->m80.y + m30.z * m64->m80.z;
        return d < func_00340F60(f * 0.01745329425f);
    }
    case 0x5E269B2B: {
        float f = 0.0f;
        func_001E7EB0(params, 0, &f, 1);
        return m30.y < func_00340F60(f * 0.01745329425f);
    }
    case 0xD3313E92: {
        Vec_00278008* pos = &m20;
        float f = 0.0f;
        func_001E7EB0(params, 0, &f, 1);
        Vec_00278008 v;
        v.q = pos->q;
        func_00101730(&v, &m64->m80);
        return func_00101C70(&v, pos, f) != 0;
    }
    case 0x97201739: {
        Vec_00278008 v;
        v.q = m_obj->m90.q;
        v.y = 0.0f;
        float a = func_00101BC8(&m_obj->m90, &v);
        if (m_obj->m90.y < 0.0f)
            a = -a;
        func_001E72B0(script->m_params, 0xA733BA7A, a);
        func_001E72B0(script->m_params, 0x21AFFF16, a - m60);
        m60 = a;
        break;
    }
    case 0x8E7833BE: {
        float a = func_00340F60(m_obj->m90.x) * 57.29577637f;
        if (m_obj->m90.z < 0.0f)
            a = 360.0f - a;
        func_001E72B0(script->m_params, 0xFD4BC03E, a);
        func_001E72B0(script->m_params, 0x2315EF17, m_obj->m90.x);
        func_001E72B0(script->m_params, 0x26910CC0, m_obj->m90.z);
        return 1;
    }
    default:
        return 2;
    }
    return 1;
}
