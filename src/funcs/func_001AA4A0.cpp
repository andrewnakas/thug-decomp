/* sym: __15Feeler_001AA4A0 = 0x00209240 */
typedef int qword_001AA4A0 __attribute__((mode(TI)));

struct Vec_001AA4A0 {
    union {
        struct { float x, y, z, w; };
        qword_001AA4A0 q;
    };
};

extern "C" void func_00183CB8(void* obj, void* ref);

struct Ref_001AA4A0 {
    void* m_obj;
    ~Ref_001AA4A0()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

struct Feeler_001AA4A0 {
    Vec_001AA4A0 m_start;
    Vec_001AA4A0 m_end;
    int m20[40];
    Ref_001AA4A0 mC0;
    int mC4[7];
    Feeler_001AA4A0();
};

extern "C" int func_002093E8(Feeler_001AA4A0* f, int a, int b);

extern "C" int func_001AA4A0(Vec_001AA4A0* start, Vec_001AA4A0* end)
{
    Feeler_001AA4A0 f;
    f.m_start = *start;
    f.m_end = *end;
    return func_002093E8(&f, 1, 0);
}
