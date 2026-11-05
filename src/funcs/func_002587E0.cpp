typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_002587E0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_002587E0() {}
    Vec_002587E0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

extern "C" void func_003233B8(Vec_002587E0* dst, Vec_002587E0* src);

struct Obj_002587E0 {
    char m_pad0[0x10];
    Vec_002587E0 m10;
    char m_pad20[0x30];
    Vec_002587E0 m50;
    char m_pad60[0x20];
    Vec_002587E0 m80;
    Vec_002587E0 m90;
    char m_padA0[0x1C];
    float mBC;
    float mC0;
    int mC4;
    float mC8;
    int Update();
};

extern "C" void func_002591D0(Obj_002587E0* self);

int Obj_002587E0::Update()
{
    Vec_002587E0 d1(m10.x - m80.x, m10.y - m80.y, m10.z - m80.z, m10.w - m80.w);
    Vec_002587E0 d2(m80.x - m90.x, m80.y - m90.y, m80.z - m90.z, m80.w - m90.w);
    Vec_002587E0 d3(m90.x - m80.x, m90.y - m80.y, m90.z - m80.z, m90.w - m80.w);
    float len = d1.Length() + mC8;
    mC8 = 0.0f;
    mBC = d2.Length();
    mC0 = len;
    m50 = d3;
    func_003233B8(&m50, &m50);
    func_002591D0(this);
    return 1;
}
