typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_0027D7D8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void Normalize(float len)
    {
        float l = Length();
        if (l > 0.0f) {
            float s = len / l;
            x *= s;
            y *= s;
            z *= s;
        }
    }
    Vec_0027D7D8& operator+=(const Vec_0027D7D8& o) { x += o.x; y += o.y; z += o.z; w += o.w; return *this; }
};

extern "C" float func_002032A0(unsigned int name, int def);

struct Body_0027D7D8 {
    char m_pad0[0xB0];
    Vec_0027D7D8 mB0;
};

struct Obj_0027D7D8 {
    char m_pad0[0xC];
    Body_0027D7D8* mC;
    char m_pad10[0x84];
    float m94;
    char m_pad98[0x388 - 0x98];
    int m388;
    void Update();
};

extern "C" int func_0027D958(Obj_0027D7D8* self);

void Obj_0027D7D8::Update()
{
    m388 = 1;
    if (func_0027D958(this)) {
        m388 = 0;
        return;
    }
    float len = mC->mB0.Length();
    if (len < func_002032A0(0xE5D73F6F, 0) * 2.0f * m94) {
        mC->mB0.Set(0.0f, 0.0f, 0.0f, 1.0f);
    } else {
        Vec_0027D7D8 d = mC->mB0;
        d.Normalize(-func_002032A0(0xE5D73F6F, 0) * m94);
        mC->mB0 += d;
    }
}
