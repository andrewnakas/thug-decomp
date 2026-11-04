typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);

struct Vec_002591D0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_002591D0() {}
    Vec_002591D0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

extern "C" bool func_00229EB0(void* p);
extern "C" void* func_00229F48(void* p, int i);
extern "C" void func_0022A090(void* p, Vec_002591D0* out);

struct Obj_002591D0 {
    char pad[0x10];
    Vec_002591D0 m10;
    char pad2[0x74 - 0x20];
    void* m74;
    char pad3[0x90 - 0x78];
    Vec_002591D0 m90;
    char pad4[0xB0 - 0xA0];
    float mB0;
    float mB4;
    float mB8;
    char pad5[0xC4 - 0xBC];
    int mC4;
    bool Update();
};

bool Obj_002591D0::Update()
{
    if (mB0 != 0.0f) {
        if (!func_00229EB0(m74)) return false;
        Vec_002591D0 v;
        func_0022A090(func_00229F48(m74, 0), &v);
        v.x -= m90.x;
        v.y -= m90.y;
        v.z -= m90.z;
        v.w -= m90.w;
        float d = v.Length();
        if (d < mB0) {
            mB8 = d * 0.5f;
            v = Vec_002591D0(m90.x - m10.x, m90.y - m10.y, m90.z - m10.z, m90.w - m10.w);
            float l = v.Length();
            if (l < mB8) mB8 = l;
            mC4 |= 1;
            return true;
        }
    }
    mC4 &= ~1;
    mB8 = mB0;
    return true;
}
