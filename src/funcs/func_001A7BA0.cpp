typedef int qword __attribute__((mode(TI)));

struct Vec_001A7BA0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001A7BA0() {}
    Vec_001A7BA0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Length() const;
};

extern "C" float sqrtf(float);

inline float Vec_001A7BA0::Length() const
{
    return sqrtf(x * x + y * y + z * z);
}

inline Vec_001A7BA0 operator-(const Vec_001A7BA0& a, const Vec_001A7BA0& b)
{
    return Vec_001A7BA0(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void* func_00229DF0(int node);

struct Obj_001A7BA0 {
    int m_pad[20];
    Vec_001A7BA0 m50;
};

struct C_001A7BA0 {
    int m_pad[3];
    Obj_001A7BA0* mC;
    int m10[3];
    int m1C;
    int m20;
    float m24;
    int m28[66];
    Vec_001A7BA0 m130;
    float m140;
    float m144;
    float m148;
    float m14C;
    int m150;
    int m154[27];
    Vec_001A7BA0 m1C0;
    void Follow(void* node);
    int MoveTo(void* params, void* script, const Vec_001A7BA0* target, int node);
};

int C_001A7BA0::MoveTo(void* params, void* script, const Vec_001A7BA0* target, int node)
{
    int units = 2;
    m130 = *target;
    Obj_001A7BA0* o = mC;
    Vec_001A7BA0 d(m130.x - o->m50.x, m130.y - o->m50.y, m130.z - o->m50.z, m130.w - o->m50.w);
    m140 = d.Length();
    m14C = 0.0f;
    m1C0 = mC->m50;
    m144 = 0.0f;
    m1C = (m1C | 8) & ~0x10;
    m150 = -1;
    float time;
    float speed;
    if (func_001E7EB0(params, 0x906B67BA, &time, 0)) {
        m24 = m140 / time;
    } else if (func_001E7EB0(params, 0xF0D90109, &speed, 0)) {
        if (!func_001E8708(params, 0x2CE7EE02)) {
            if (func_001E8708(params, 0xAAD7C80F))
                units = 1;
            else if (func_001E8708(params, 0xA18B8F32))
                units = 0;
        }
        func_001E7EB0(params, 0x85894A84, &m14C, 0);
        if (units == 2) {
            speed *= 17.6f;
            m14C *= 17.6f;
        } else if (units == 1) {
            speed *= 12.0f;
            m14C *= 12.0f;
        }
        if (m14C == 0.0f) {
            m24 = speed;
        } else {
            m24 = 0.0f;
            m148 = speed;
        }
    } else {
        mC->m50 = m130;
        m1C &= ~8;
        if (node != -1 && func_001E8708(params, 0x90A91232)) Follow(func_00229DF0(node));
        return 1;
    }
    return 0;
}
