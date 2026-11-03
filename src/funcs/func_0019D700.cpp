typedef int qword __attribute__((mode(TI)));

struct Vec_0019D700 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0019D700 {
    Vec_0019D700 row[4];
};

extern "C" int func_001E8398(void* params, unsigned int name, void* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7F50(void* params, const char* name, float* out, int req);
extern "C" int func_001E84E8(void* params, const char* name, int* out, int req);
extern "C" int func_001E8180(void* params, unsigned int name, void** out, int req);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6A50(void* dst, void* src);
extern char D_00362210[];
extern char D_00362220[];

struct Obj_0019D700 {
    int m_pad[20];
    Vec_0019D700 m50;
    int m60[4];
    Mat_0019D700 m70;
};

struct C_0019D700 {
    int m_pad[3];
    Obj_0019D700* mC;
    int m10[3];
    int m1C;
    int m20[4];
    int m30;
    int m34;
    float m38;
    int m3C;
    float m40;
    float m44;
    int m48[3];
    float m54;
    float m58;
    float m5C;
    int m60;
    int m64;
    unsigned int m68;
    unsigned int m6C;
    int m70;
    float m74;
    int m78;
    short m7C;
    short m7E;
    unsigned int m80;
    void* m84;
    unsigned int m88;
    void* m8C;
    Vec_0019D700 m90;
    int mA0[8];
    Mat_0019D700 mC0;
    float m100;
    void Init(void* params);
};

void C_0019D700::Init(void* params)
{
    m7C = 0;
    m1C = 0;
    m100 = 0.01666666f;
    m40 = 0.9f;
    m60 = 10;
    func_001E7DE8(params, 0x767F323F, &m60, 0);
    m40 = 0.6f;
    func_001E7EB0(params, 0xAF6034DF, &m40, 0);
    m38 = 3.0f;
    func_001E7EB0(params, 0xFF08EE44, &m38, 0);
    m38 *= 12.0f;
    m30 = 360;
    func_001E7DE8(params, 0x33EE064F, &m30, 0);
    m34 = 45;
    func_001E7DE8(params, 0xDE14151D, &m34, 0);
    m3C = 0;
    func_001E7DE8(params, 0xC0F30F40, &m3C, 0);
    m54 = 32.0f;
    func_001E7EB0(params, 0xA5E2DA58, &m54, 0);
    m54 *= 12.0f;
    m58 = 1.0f;
    func_001E7EB0(params, 0x373D4E7D, &m58, 0);
    m68 = 0;
    func_001E8398(params, 0x1FB2F60C, &m68, 0);
    m6C = 0;
    func_001E8398(params, 0x29E2E9E0, &m6C, 0);
    m44 = 32.0f;
    func_001E7EB0(params, 0x3ECA5C95, &m44, 0);
    m44 *= 12.0f;
    m78 = !func_001E8708(params, 0x65BA5A75);
    m5C = 15.0f;
    func_001E7EB0(params, 0x96763C79, &m5C, 0);
    m5C *= 12.0f;
    int mode = 0;
    func_001E84E8(params, D_00362210, &mode, 0);
    m70 = 0;
    m74 = 50.0f;
    func_001E7F50(params, D_00362220, &m74, 0);
    m74 *= m74;
    func_001E8398(params, 0x58CDC0F0, &m80, 0);
    void* s1 = 0;
    func_001E8180(params, 0x24031741, &s1, 0);
    if (s1) {
        m84 = func_001E6978(func_001190D0(8));
        func_001E6A50(m84, s1);
    }
    func_001E8398(params, 0x2D075F90, &m88, 0);
    void* s2 = 0;
    func_001E8180(params, 0x346B0C03, &s2, 0);
    if (s2) {
        m8C = func_001E6978(func_001190D0(8));
        func_001E6A50(m8C, s2);
    }
    Obj_0019D700* o = mC;
    m90 = o->m50;
    Mat_0019D700* m = &mC0;
    *m = o->m70;
}
