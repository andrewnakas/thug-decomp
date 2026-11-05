typedef int qword __attribute__((mode(TI)));

struct Vec_001B99A0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Ctrl_001B99A0 {
    char pad0[0x30];
    float m_angle;
};

struct C_001B99A0 {
    char pad0[0xC];
    void* m_obj;
    char pad10[0x2C - 0x10];
    int m_type;
    char pad30[0xC0 - 0x30];
    float mC0;
    float mC4;
    float mC8;
    float mCC;
    float mD0;
    float mD4;
    char padD8[0xDC - 0xD8];
    float mDC;
    float mE0;
    float mE4;
    float mE8;
    float mEC;
    float mF0;
    char padF4[0x10C - 0xF4];
    float m10C;
    float m110;
    float m114;
    float m118;
    char pad11C[0x124 - 0x11C];
    float m124;
    char pad128[0x12C - 0x128];
    float m12C;
    float m130;
    char pad134[0x138 - 0x134];
    float m138;
    float m13C;
    float m140;
    float m144;
    char pad148[0x160 - 0x148];
    Ctrl_001B99A0* m160;
    void Setup(int type, float time);
};

extern char D_00362F50[];
extern char D_00362F70[];
extern char D_00362F90[];
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" int func_0013B0E0();
extern "C" void* func_001E55F8(const char* name, int flags);
extern "C" int func_001E9300(void* scr, int idx);
extern "C" void* func_001E5548(int id, int flags);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E8870(void* params, unsigned int name, int* out, int required);
extern "C" void func_001B8120(void* comp, float v);

void C_001B99A0::Setup(int type, float time)
{
    void* comp = func_00185578(m_obj, 0xC4E311FA);
    int mode = func_0013B0E0();
    void* scr;
    switch (mode) {
    case 1:
        scr = func_001E55F8(D_00362F50, 0);
        break;
    case 2:
        scr = func_001E55F8(D_00362F70, 0);
        break;
    default:
        scr = func_001E55F8(D_00362F90, 0);
        break;
    }
    void* p = func_001E5548(func_001E9300(scr, type), 0);
    m_type = type;
    m12C = 0.0f;
    Vec_001B99A0 v;
    float height;
    func_001E7EB0(p, 0x94DF1603, &v.x, 0);
    func_001E7EB0(p, 0x52E6C41B, &v.y, 0);
    func_001E7EB0(p, 0x0B96AE2D, &v.z, 0);
    func_001E7EB0(p, 0xE3C07609, &v.w, 0);
    func_001E7EB0(p, 0x012F6992, &height, 0);
    func_001E7EB0(p, 0x7F0032AC, &m12C, 0);
    func_001E7EB0(p, 0xADB6390E, &m130, 0);
    func_001E7EB0(p, 0xF54FB9C5, &m138, 0);
    func_001E7EB0(p, 0x2FA11029, &m13C, 0);
    func_001E7EB0(p, 0x042FD4A0, &m140, 0);
    func_001E7EB0(p, 0xAE47899B, &mE0, 0);
    func_001E7EB0(p, 0xE1E4E104, &mE4, 0);
    func_001E7EB0(p, 0xF386F4D9, &mE8, 0);
    func_001E7EB0(p, 0x4882A1FE, &mEC, 0);
    func_001E7EB0(p, 0xBEF0D195, &mF0, 0);
    m114 = 1.0f;
    m118 = 1.0f;
    m110 = 1.0f;
    float scale;
    func_001E7EB0(p, 0x748743A7, &scale, 0);
    func_001E7EB0(p, 0x5A7F5CC5, &m114, 0);
    func_001E7EB0(p, 0xD790B83D, &m110, 0);
    func_001E7EB0(p, 0xD414C22E, &m118, 0);
    m10C = scale;
    int flag;
    func_001E8870(p, 0xA1DC81F9, &flag, 0);
    mDC = v.x;
    m124 = v.w;
    m144 = height * 12.0f;
    if (time > 0.0f) {
        v.y *= 12.0f;
        v.z *= 12.0f;
        float r = (1.0f / 60.0f) / time;
        mC4 = time;
        mD0 = time;
        mC8 = (v.y - mC0) * r;
        mD4 = (v.z - mCC) * r;
    } else {
        mC4 = 0.0f;
        mD0 = 0.0f;
        mC0 = v.y * 12.0f;
        mCC = v.z * 12.0f;
    }
    switch (mode) {
    case 1:
        func_001B8120(comp, mDC * 0.5f);
        break;
    case 2:
        func_001B8120(comp, mDC);
        break;
    default:
        func_001B8120(comp, mDC);
        break;
    }
    switch (type) {
    case 5:
    case 6:
        m160->m_angle = 3.141592741f;
        break;
    case 7:
    case 8:
        m160->m_angle = 1.570796371f;
        break;
    case 11:
    case 12:
        m160->m_angle = -1.570796371f;
        break;
    case 9:
    case 10:
    default:
        m160->m_angle = 0.0f;
        break;
    }
}
