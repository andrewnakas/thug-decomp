typedef int qword __attribute__((mode(TI)));

struct Vec_00123F00 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00123F00& operator=(const Vec_00123F00& o)
    {
        q = o.q;
        return *this;
    }
};

struct Col_00123F00 {
    unsigned char r, g, b, a;
};

struct Tex_00123F00 {
    float m0;
    Vec_00123F00 m10;
    float m20;
    float m24;
    int m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    Col_00123F00 m48;
};

extern "C" int func_0010FC30();

class Obj_00123F00 {
public:
    int m0[3];
    unsigned int m_flags;
    char pad10[0x80 - 0x10];
    Tex_00123F00 m80;
    Tex_00123F00 mD0;
    int m_time;
    int m_mode;
    int m128;
    int m12C;
    void Start(int mode);
};

void Obj_00123F00::Start(int mode)
{
    m_time = func_0010FC30();
    m_mode = mode;
    m128 = 0;
    m12C = 0;
    if (!mode) {
        m80 = mD0;
    }
    m_flags |= 0x400;
    m_flags &= ~0x20000;
    m_flags &= ~0x40000;
}
