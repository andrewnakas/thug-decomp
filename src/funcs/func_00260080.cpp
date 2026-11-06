extern char D_00375910[];
extern char D_00375930[];
extern char D_00375950[];
extern char D_00375968[];
extern char D_00390CF8[];
extern char D_00390D00[];
extern char D_00390D08[];
extern char D_00375978[];
extern char D_00375988[];
extern char D_00375998[];
extern char D_00390D10[];
extern char D_003759A8[];
extern char D_003759B8[];
extern char D_00390D18[];
extern char D_00390D20[];
extern char D_003759D0[];
extern char D_003759E8[];
extern char D_003759F8[];
extern char D_00375A08[];
extern char D_00375A18[];
extern char D_00375A28[];
extern char D_00375A40[];
extern char D_00390D28[];
extern "C" int func_0013B0E0();
extern "C" void* func_001E55F8(const char* name, int a);
extern "C" unsigned int func_001E9300(void* arr, int index);
extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" bool func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" bool func_001E8890(void* params, const char* name, const char** out, int required);

struct Cam_00260080;
extern "C" void func_00114D28(Cam_00260080* self, float f);

struct Cam_00260080 {
    char pad[0xD0];
    int m_D0;
    char padD4[0x10C - 0xD4];
    float m_10C;
    char pad110[0x180 - 0x110];
    float m_180;
    float m_184;
    float m_188;
    float m_18C;
    float m_190;
    float m_194;
    char pad198[0x1A4 - 0x198];
    float m_1A4;
    float m_1A8;
    float m_1AC;
    float m_1B0;
    char pad1B4[0x1DC - 0x1B4];
    float m_1DC;
    char pad1E0[0x1F4 - 0x1E0];
    float m_1F4;
    char pad1F8[4];
    float m_1FC;
    float m_200;
    float m_204;
    float m_208;
    float m_20C;
    float m_210;
    char pad214[0x230 - 0x214];
    float m_230;
    float m_234;
    float m_238;
    float m_23C;
    float m_240;
    void Set(int idx, float t);
};

void Cam_00260080::Set(int idx, float t)
{
    void* arr;
    switch (func_0013B0E0()) {
    case 1:
        arr = func_001E55F8(D_00375910, 0);
        break;
    case 2:
        arr = func_001E55F8(D_00375930, 0);
        break;
    default:
        arr = func_001E55F8(D_00375950, 0);
        break;
    }
    void* params = func_001E5548(func_001E9300(arr, idx), 0);
    m_D0 = idx;
    m_1FC = 0;
    float fov;
    float x;
    float z;
    float dist;
    float height;
    float roll;
    func_001E7F50(params, D_00375968, &fov, 0);
    func_001E7F50(params, D_00390CF8, &x, 0);
    func_001E7F50(params, D_00390D00, &z, 0);
    func_001E7F50(params, D_00390D08, &dist, 0);
    func_001E7F50(params, D_00375978, &height, 0);
    func_001E7F50(params, D_00375988, &m_1FC, 0);
    func_001E7F50(params, D_00375998, &m_200, 0);
    func_001E7F50(params, D_00390D10, &m_204, 0);
    func_001E7F50(params, D_003759A8, &m_208, 0);
    func_001E7F50(params, D_003759B8, &m_20C, 0);
    func_001E7F50(params, D_00390D18, &m_230, 0);
    func_001E7F50(params, D_00390D20, &m_234, 0);
    func_001E7F50(params, D_003759D0, &m_238, 0);
    func_001E7F50(params, D_003759E8, &m_23C, 0);
    func_001E7F50(params, D_003759F8, &m_240, 0);
    m_1AC = 1.0f;
    m_1B0 = 1.0f;
    m_1A8 = 1.0f;
    func_001E7F50(params, D_00375A08, &roll, 0);
    func_001E7F50(params, D_00375A18, &m_1AC, 0);
    func_001E7F50(params, D_00375A28, &m_1A8, 0);
    func_001E7F50(params, D_00375A40, &m_1B0, 0);
    m_1A4 = roll;
    const char* name;
    func_001E8890(params, D_00390D28, &name, 0);
    m_10C = fov;
    m_1F4 = dist;
    m_210 = height * 12.0f;
    if (t > 0.0f) {
        x *= 12.0f;
        z *= 12.0f;
        float inv = 0.016666668f / t;
        m_184 = t;
        m_190 = t;
        m_188 = (x - m_180) * inv;
        m_194 = (z - m_18C) * inv;
    } else {
        m_184 = 0.0f;
        m_190 = 0.0f;
        m_180 = x * 12.0f;
        m_18C = z * 12.0f;
    }
    if (this) {
        switch (func_0013B0E0()) {
        case 1:
            func_00114D28(this, m_10C * 0.5f);
            break;
        case 2:
            func_00114D28(this, m_10C);
            break;
        default:
            func_00114D28(this, m_10C);
            break;
        }
    }
    switch (idx) {
    case 5:
    case 6:
        m_1DC = 3.1415927f;
        break;
    case 7:
    case 8:
        m_1DC = 1.5707964f;
        break;
    case 11:
    case 12:
        m_1DC = -1.5707964f;
        break;
    default:
        m_1DC = 0.0f;
        break;
    }
}
