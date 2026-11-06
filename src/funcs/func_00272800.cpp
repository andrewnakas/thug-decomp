typedef int qword __attribute__((mode(TI)));

struct Vec_00272800 {
    union {
        qword q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    void Negate()
    {
        c[0] = -c[0];
        c[1] = -c[1];
        c[2] = -c[2];
    }
};

struct VecC_00272800 : Vec_00272800 {
    VecC_00272800(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
};
static inline VecC_00272800 operator-(const Vec_00272800& a, const Vec_00272800& b) { return VecC_00272800(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }

struct Mat_00272800;
extern "C" void func_00323318(Mat_00272800* d, const Mat_00272800* a, Mat_00272800* b);
extern "C" Mat_00272800* func_00100890(Mat_00272800* out, float a);
extern "C" Mat_00272800* func_00100928(Mat_00272800* out, float a);
extern "C" Mat_00272800* func_001009C0(Mat_00272800* out, float a);

struct Mat_00272800 {
    Vec_00272800 r[4];
    Mat_00272800() {}
    const Vec_00272800& operator[](int i) const { return r[i]; }
    Mat_00272800(const Mat_00272800& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_00272800& operator=(const Mat_00272800& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    Mat_00272800 operator*(const Mat_00272800& b) const;
};

inline Mat_00272800 Mat_00272800::operator*(const Mat_00272800& b) const
{
    Mat_00272800 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

struct Body_00272800 {
    char pad[0x50];
    Vec_00272800 m50;
    char pad60[0x10];
    Mat_00272800 m70;
};

struct Model_00272800 {
    char pad0[0xC];
    Body_00272800* mC;
    char pad10[0x10];
    Mat_00272800 m20;
    char pad60[0x3B0 - 0x60];
    int m3B0;
};

extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int a);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_001E8398(void* params, unsigned int name, int* out, int a);
extern "C" void* func_00229668(int id, int a);
extern "C" void func_0022A090(void* obj, Vec_00272800* out);
extern "C" float func_00101A10(Mat_00272800* m, Vec_00272800* v, int a, int b);

struct Base_00272800 {
    char pad0[0xC];
    Body_00272800* mC;
    char pad10[8];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void Refresh(int a);
};

struct Comp_00272800 : Base_00272800 {
    float m1C;
    float m20;
    float m24;
    int m28;
    int m2C;
    float m30;
    float m34;
    float m38;
    int m3C;
    int m40;
    float m44;
    float m48;
    float m4C;
    int m50;
    int m54;
    Model_00272800* m58;
    int CallMember(unsigned int name, void* params);
};

int Comp_00272800::CallMember(unsigned int name, void* params)
{
    if (name == 0xC876ADF3) {
        float time;
        if (func_001E7EB0(params, 0x79A07F3F, &time, 0)) {
            if (!func_001E8708(params, 0xD029F619) && !func_001E8708(params, 0x49E0EE96)) {
                if (func_001E8708(params, 0x019176C5) || func_001E8708(params, 0x4A07C332))
                    time *= 0.01666666754f;
                else
                    time *= 0.001000000047f;
            }
            if (func_001E7EB0(params, 0x7323E97C, &m1C, 0)) {
                float x = m1C;
                m2C = 1;
                m20 = time;
                m28 = 0;
                m1C = __builtin_fabsf(x * 0.01745329425f);
                m24 = x / time * 0.01745329425f;
            }
            if (func_001E7EB0(params, 0x0424D9EA, &m30, 0)) {
                float x = m30;
                m40 = 1;
                m34 = time;
                m3C = 0;
                m30 = __builtin_fabsf(x * 0.01745329425f);
                m38 = x / time * 0.01745329425f;
            }
            if (func_001E7EB0(params, 0x9D2D8850, &m44, 0)) {
                float x = m44;
                m54 = 1;
                m48 = time;
                m50 = 0;
                m44 = __builtin_fabsf(x * 0.01745329425f);
                m4C = x / time * 0.01745329425f;
            }
            int target = 0;
            if (func_001E8398(params, 0x7A8017BA, &target, 0)) {
                Vec_00272800 p;
                func_0022A090(func_00229668(target, 1), &p);
                Body_00272800* b = mC;
                VecC_00272800 d = p - b->m50;
                float x = func_00101A10(&b->m70, &d, 2, 1) * 57.29577637f;
                m34 = time;
                m40 = 1;
                m3C = 0;
                m30 = __builtin_fabsf(x * 0.01745329425f);
                m38 = x / time * 0.01745329425f;
            }
            Refresh(0);
            return 1;
        }
        float ang;
        if (func_001E7EB0(params, 0x7323E97C, &ang, 0)) {
            Mat_00272800 rot;
            Mat_00272800& m = mC->m70;
            m = *func_00100890(&rot, ang * 0.01745329425f) * m;
            m58->m20 = m58->mC->m70;
        } else if (func_001E7EB0(params, 0x0424D9EA, &ang, 0)) {
            Mat_00272800& m = mC->m70;
            m = *func_00100928((Mat_00272800*)0x70003FC0, ang * 0.01745329425f) * m;
            m58->m20 = m58->mC->m70;
        } else if (func_001E7EB0(params, 0x9D2D8850, &ang, 0)) {
            Mat_00272800 rot;
            Mat_00272800& m = mC->m70;
            m = *func_001009C0(&rot, ang * 0.01745329425f) * m;
            m58->m20 = m58->mC->m70;
        } else {
            mC->m70.r[2].Negate();
            mC->m70.r[0].Negate();
            m58->m20 = m58->mC->m70;
            m58->m3B0 ^= 1;
        }
    } else {
        return 2;
    }
    return 1;
}
