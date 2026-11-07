/* fuzzy: 96.9 */
struct Vec_0021A4D0 {
    float x, y, z, w;
    Vec_0021A4D0() {}
    Vec_0021A4D0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_0021A4D0(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
    Vec_0021A4D0 operator-(const Vec_0021A4D0& o) const { return Vec_0021A4D0(x - o.x, y - o.y, z - o.z, w - o.w); }
    Vec_0021A4D0 operator*(float s) const { return Vec_0021A4D0(x * s, y * s, z * s, w * s); }
    Vec_0021A4D0& operator-=(const Vec_0021A4D0& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

struct Pool_0021A4D0 {
    char pad[0x11C];
    int m11C;
};

extern Pool_0021A4D0* D_00388A70;
extern char D_0038F340[];
extern char D_003713E8[];
extern char D_00371430[];
extern char D_00371410[];
extern char D_00371448[];
extern "C" void func_00123620();
extern "C" void func_0010A950(Pool_0021A4D0* pool, int a);
extern "C" void func_0010A9B0(Pool_0021A4D0* pool);
extern "C" int func_001E8708(void* s, unsigned int key);
extern "C" int func_001E7C80(void* s, int idx, char** out, int f);
extern "C" int  func_00103F28(const char* fmt, ...);
extern "C" int func_00110DC8(const char* name);
extern "C" char* func_0010E1E8(const char* name, int* size, int a, int b);
extern "C" void* func_00334100(const char* p);
extern "C" float func_0033E9B8(void* p);
extern "C" void func_001235F0(Vec_0021A4D0* a, Vec_0021A4D0* b, int c0, int c1, int f);
extern "C" void func_0010BEB8(void* p);

static inline bool IsNum_0021A4D0(unsigned char c)
{
    return c == '-' || c == '.' || (c >= '0' && c <= '9');
}

extern "C" bool func_0021A4D0(void* s)
{
    func_00123620();
    func_0010A950(D_00388A70, D_00388A70->m11C);
    int showA = func_001E8708(s, 0xB426BF5A);
    int showB = func_001E8708(s, 0x14240297);
    int showC = func_001E8708(s, 0x969D3AF6);
    int showD = func_001E8708(s, 0xB0FE7369);
    if (!showA && !showB && !showC && !showD) {
        showA = showB = showC = showD = 1;
    }
    char* name = D_0038F340;
    func_001E7C80(s, 0, &name, 0);
    if (name[1] == ':') {
        func_00103F28(D_003713E8);
        name += 2;
    }
    int size = 0;
    if (!func_00110DC8(name)) {
        func_00103F28(D_00371430, name);
        return false;
    }
    char* buf = func_0010E1E8(name, &size, 0, 0);
    int nA = 0;
    func_00103F28(D_00371410, name, size, buf);
    int nB = 0;
    int nC = 0;
    int nD = 0;
    func_0010A9B0(D_00388A70);
    for (char* p = buf; p < buf + size; p++) {
        if (p[0] == '\n' && p[1] == 'T' && p[2] == 'r' && p[3] == 'a' && p[4] == 'c' && p[5] == 'k' &&
            p[6] == 'i' && p[7] == 'n' && p[8] == 'g') {
            int type = p[9] - '0';
            char* q = p + 11;
            float v[6];
            for (int i = 0; i < 6; i++) {
                void* t = func_00334100(q);
                float* pv = &v[i];
                *pv = func_0033E9B8(t);
                unsigned char c;
                do {
                    c = *q++;
                } while (c == '-' || c == '.' || (c >= '0' && c <= '9'));
            }
            p = q - 1;
            Vec_0021A4D0 a(v[0], v[1], v[2]);
            Vec_0021A4D0 b(v[3], v[4], v[5]);
            int color;
            switch (type) {
            case 1:
                nA++;
                if (!showA) continue;
                color = 0xFFFFFF;
                a -= (b - a) * 10.0f;
                break;
            case 2:
                nB++;
                if (!showB) continue;
                color = 0xFF;
                break;
            case 3:
                nC++;
                if (!showC) continue;
                color = 0xFFFF00;
                a -= (b - a) * 2.0f;
                break;
            case 4:
                nD++;
                if (!showD) continue;
                color = 0x8000;
                a -= (b - a) * 4.0f;
                break;
            default:
                color = 0xFFFF;
                break;
            }
            func_001235F0(&a, &b, color, color, 0);
        }
    }
    func_00103F28(D_00371448, nA, nB, nC, nD);
    func_0010BEB8(buf);
    return true;
}
