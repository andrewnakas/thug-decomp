/* sym: __12Box_001AAC48 = 0x001022D8 */
typedef int qword __attribute__((mode(TI)));

struct Row_001AAC48 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    struct Vec_001AAC48 operator-(const Row_001AAC48& b) const;
};

struct Vec_001AAC48 : Row_001AAC48 {
    Vec_001AAC48() {}
    Vec_001AAC48(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001AAC48(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 1.0f; }
};



inline Vec_001AAC48 Row_001AAC48::operator-(const Row_001AAC48& b) const
{
    return Vec_001AAC48(x - b.x, y - b.y, z - b.z, w - b.w);
}

struct Mat_001AAC48 {
    Row_001AAC48 r[4];
    Mat_001AAC48() {}
    Mat_001AAC48& operator=(const Mat_001AAC48& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

struct Box_001AAC48 {
    Row_001AAC48 mn;
    Row_001AAC48 mx;
    Box_001AAC48();
};

struct Obj_001AAC48 {
    char pad0[0x50];
    Row_001AAC48 m50;
    char pad60[0x70 - 0x60];
    Mat_001AAC48 m70;
    char padB0[0xC0 - 0xB0];
    Mat_001AAC48 mC0;
    bool InBox(const Box_001AAC48& b) const
    {
        return m50.x >= b.mn.x && m50.y >= b.mn.y && m50.z >= b.mn.z && m50.x <= b.mx.x && m50.y <= b.mx.y
            && m50.z <= b.mx.z;
    }
};

struct Comp_001AAC48 {
    char pad0[0x20];
    int m20;
};

struct Path_001AAC48 {
    char pad0[0x90];
    Row_001AAC48 m90;
};

struct Ctl_001AAC48 {
    char pad0[0xC];
    Obj_001AAC48* m_obj;
    char pad10[0x1C - 0x10];
    float m1C;
    char m20[0xC0 - 0x20];
    float mC0;
    char padC4[0xD0 - 0xC4];
    Row_001AAC48 mD0;
    Row_001AAC48 mE0;
    int mF0;
    Vec_001AAC48 ToTarget(const Row_001AAC48& p) const
    {
        return Vec_001AAC48(mD0.x - p.x, mD0.y - p.y, mD0.z - p.z, mD0.w - p.w);
    }
    Vec_001AAC48 Grow(const Row_001AAC48& p) const
    {
        return Vec_001AAC48(mE0.x + p.x, mE0.y + p.y, mE0.z + p.z, mE0.w + p.w);
    }
    int CallMember(unsigned int key, void* params);
};

extern char D_00362898[];
extern char D_003628A8[];
extern char D_003628C8[];
extern char D_003628E0[];
extern char D_003628F0[];
extern char D_0038CF10[];
extern "C" unsigned int func_001E7F50(void* params, char* name, float* out, int req);
extern "C" float func_001AA6E8(Ctl_001AAC48* self);
extern "C" float func_001AA3F0(void* params, float a);
extern "C" int func_001AA9D8(Ctl_001AAC48* self, Mat_001AAC48* m, Mat_001AAC48* out, float a, float b, float c);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" float func_00101A10(Mat_001AAC48* m, Row_001AAC48* dir, int i, int j);
extern "C" void func_00103000(void* slerp, Mat_001AAC48* a, Mat_001AAC48* b);
extern "C" void func_001AA518(Ctl_001AAC48* self, float a, void* params);
extern "C" float func_0010FAB8();
extern "C" void func_00103930(void* slerp, Mat_001AAC48* out, float t);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_001A0D78(void* p);
extern "C" Path_001AAC48* func_001A67A8(void* p);

static inline float Frames_001AAC48()
{
    return func_0010FAB8() * 60.0f;
}

static inline float Secs_001AAC48()
{
    return Frames_001AAC48() * 0.016666668f;
}

int Ctl_001AAC48::CallMember(unsigned int key, void* params)
{
    switch (key) {
    case 0x6157CBC0: {
        Obj_001AAC48* o = m_obj;
        Mat_001AAC48 m = o->mC0;
        m.r[3] = o->m50;
        float dist = 100.0f;
        func_001E7F50(params, D_00362898, &dist, 0);
        float ang = func_001AA6E8(this);
        Mat_001AAC48 res;
        if (!func_001AA9D8(this, &m, &res, ang, func_001AA3F0(params, ang), dist)) {
            float a1 = ang + 180.0f;
            if (func_001AA9D8(this, &m, &res, a1, func_001AA3F0(params, a1), dist)) {
                func_00103F28(D_003628A8);
            } else {
                float a2 = ang - 90.0f;
                if (func_001AA9D8(this, &m, &res, a2, func_001AA3F0(params, a2), dist)) {
                    func_00103F28(D_003628C8);
                } else {
                    Vec_001AAC48 d;
                    d = ToTarget(m.r[3]);
                    float a3 = func_00101A10(&m_obj->m70, &d, 2, 1);
                    if (!func_001AA9D8(this, &m, &res, a3, func_001AA3F0(params, a3), dist)) {
                        res = m;
                        return 0;
                    }
                }
            }
        }
        res.r[0] = m.r[0];
        res.r[1] = m.r[1];
        res.r[2] = m.r[2];
        func_00103000(m20, &m, &res);
        Vec_001AAC48 d;
        d = res.r[3] - m.r[3];
        mC0 = 0.0f;
        func_001AA518(this, func_00101A10(&m_obj->m70, &d, 2, 1), params);
        break;
    }
    case 0xD2AA4D2D: {
        float v;
        v = func_001E7F50(params, D_0038CF10, &v, 1);
        Box_001AAC48 box;
        box.mn = ToTarget(Vec_001AAC48(v, v, v));
        box.mx = Grow(Vec_001AAC48(v, v, v));
        if (!m_obj->InBox(box)) {
            func_00103F28(D_003628F0);
            return 0;
        }
        func_00103F28(D_003628E0);
        return 0;
    }
    case 0x41226942: {
        mC0 += m1C * Secs_001AAC48();
        Mat_001AAC48 m;
        func_00103930(m20, &m, mC0);
        m_obj->m50 = m.r[3];
        m_obj->m70 = m;
        m_obj->m70.r[3] = Vec_001AAC48(0.0f, 0.0f, 0.0f, 1.0f);
        break;
    }
    case 0x3C7F8F3E: {
        int r;
        if (mC0 >= 1.0f && func_001A0D78(func_00185578(m_obj, 0x72AD7B23)))
            r = 1;
        else
            r = 0;
        return r;
    }
    case 0x6A4BCA91:
        mD0 = m_obj->m50;
        break;
    case 0x3FB422E8: {
        void* p = func_00185578(m_obj, 0x0A015E17);
        if (p && func_001A67A8(p))
            mE0 = func_001A67A8(p)->m90;
        else
            mE0 = m_obj->m50;
        break;
    }
    case 0x539A32DC: {
        Comp_001AAC48* c = (Comp_001AAC48*)func_00185578(m_obj, 0x0A015E17);
        mF0 = (c->m20 |= 4) != 0;
        break;
    }
    case 0x53BC3B4E: {
        Comp_001AAC48* c = (Comp_001AAC48*)func_00185578(m_obj, 0x0A015E17);
        if (!c)
            break;
        if (mF0)
            c->m20 |= 4;
        else
            c->m20 &= ~4;
        break;
    }
    default:
        return 2;
    }
    return 1;
}
