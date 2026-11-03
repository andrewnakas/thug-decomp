typedef int qword __attribute__((mode(TI)));

struct Vec_001A2A18 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001A2A18() {}
    Vec_001A2A18(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

extern "C" float func_001E5318(unsigned int name, int flag);

struct Layer_001A2A18 {
    int m0;
    int m4;
    int m8[2];
    Vec_001A2A18 m10;
    Vec_001A2A18 m20;
    Vec_001A2A18 m30;
    Vec_001A2A18 m40;
    int m50;
    int m54[3];
    Vec_001A2A18 m60;
    Vec_001A2A18 m70;
    Vec_001A2A18 m80;
    Vec_001A2A18 m90;
    int mA0[4];
    Vec_001A2A18 mB0;
    Vec_001A2A18 mC0;
    Vec_001A2A18 mD0;
    Vec_001A2A18 mE0;
};

struct C_001A2A18 {
    int m_pad[24];
    int m60;
    Layer_001A2A18* m64;
    int Add(int id);
};

int C_001A2A18::Add(int id)
{
    if (m60 >= 12) return 0;
    Layer_001A2A18* e = &m64[m60];
    e->m4 = 0;
    e->m50 = 1;
    e->m0 = id;
    e->m10.x = func_001E5318(0x802638F7, 0);
    e->m10.y = func_001E5318(0xF7210861, 0);
    e->m10.z = func_001E5318(0x6E2859DB, 0);
    e->m10.w = 1.0f;
    e->m20.x = func_001E5318(0x5D39CFDA, 0);
    e->m20.y = func_001E5318(0x2A3EFF4C, 0);
    e->m20.z = func_001E5318(0xB337AEF6, 0);
    e->m20.w = 1.0f;
    e->m40 = Vec_001A2A18(0.0f, 0.0f, 0.0f, 0.0f);
    e->m30 = Vec_001A2A18(32.0f, 32.0f, 32.0f, 0.0f);
    e->m60.x = func_001E5318(0x2DAFA9C5, 0) * 2.0f * 0.0007669904153f;
    e->m60.y = func_001E5318(0x5AA89953, 0) * 2.0f * 0.0007669904153f;
    e->m60.z = func_001E5318(0xC3A1C8E9, 0) * 2.0f * 0.0007669904153f;
    e->m60.w = 1.0f;
    e->m70.x = func_001E5318(0xF0B05EE8, 0) * 2.0f * 0.0007669904153f;
    e->m70.y = func_001E5318(0x87B76E7E, 0) * 2.0f * 0.0007669904153f;
    e->m70.z = func_001E5318(0x1EBE3FC4, 0) * 2.0f * 0.0007669904153f;
    e->m70.w = 1.0f;
    e->m90 = Vec_001A2A18(0.0f, 0.0f, 0.0f, 0.0f);
    e->m80 = Vec_001A2A18(32.0f, 32.0f, 32.0f, 0.0f);
    e->mB0.x = 1.0f;
    e->mB0.y = 1.0f;
    e->mB0.z = 1.0f;
    e->mB0.w = 1.0f;
    e->mC0.x = 1.0f;
    e->mC0.y = 1.0f;
    e->mC0.z = 1.0f;
    e->mC0.w = 1.0f;
    e->mE0 = Vec_001A2A18(0.0f, 0.0f, 0.0f, 0.0f);
    e->mD0 = Vec_001A2A18(32.0f, 32.0f, 32.0f, 0.0f);
    m60++;
    return 1;
}
