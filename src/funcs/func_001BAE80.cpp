/* sym: __15Feeler_001BAE80 = 0x00209240 */
typedef int qword_001BAE80 __attribute__((mode(TI)));

struct Vec_001BAE80 {
    union {
        struct { float x, y, z, w; };
        qword_001BAE80 q;
    };
    const float& operator[](int i) const { return (&x)[i]; }
    int operator==(const Vec_001BAE80& b) const
    {
        return x == b[0] && y == b[1] && z == b[2] && w == b[3];
    }
};


extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_001BB4B8();

struct Ref_001BAE80 {
    void* m_obj;
    ~Ref_001BAE80()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

struct Feeler_001BAE80 {
    Vec_001BAE80 m_start;
    Vec_001BAE80 m_end;
    void* m_callback;
    int m24[39];
    Ref_001BAE80 mC0;
    int mC4[3];
    void* m_data;
    int mD4[3];
    Feeler_001BAE80();
};

extern "C" int func_002093E8(Feeler_001BAE80* f, int a, int b);
extern "C" void func_00209350(Feeler_001BAE80* f, int a, int size);

struct Model_001BAE80 {
    char pad[0x50];
    Vec_001BAE80 m50;
    char pad60[0x104 - 0x60];
    unsigned int m104;
};

struct Obj_001BAE80 {
    char pad[0xC];
    Model_001BAE80* mC;
    char pad10[0x10];
    Vec_001BAE80 m20;
    void Method();
};

void Obj_001BAE80::Method()
{
    if (m20 == mC->m50)
        return;
    if (mC->m104 & 8) {
        m20 = mC->m50;
        return;
    }
    Feeler_001BAE80 f;
    f.m_start = m20;
    f.m_end = mC->m50;
    func_00209350(&f, 0, 0x50);
    f.m_callback = (void*)func_001BB4B8;
    f.m_data = this;
    func_002093E8(&f, 1, 0);
    m20 = mC->m50;
}
