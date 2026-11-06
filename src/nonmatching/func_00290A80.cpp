/* fuzzy: 98.7 */
/* nonmatch func_00290A80: best earlier draft (thug-claude-lane3/work/w53/p6/func_00290A80.fail), 7 of 375 words differ. */
struct Sub_00290A80 {
    char pad[0x34];
    float m34;
    float m38;
    float m3C;
    float m40;
    char pad44[0x80 - 0x44];
};

struct Lnk_00290A80 {
    char pad[0x1C];
    void* m1C;
};

struct Obj_00290A80;
static inline float Sign_00290A80(float x)
{
    float r = 1.0f;
    if (x < 0.0f)
        r = -1.0f;
    return r;
}
extern "C" int func_001E8708(void* p, unsigned int key);
extern "C" void func_00260A18(Sub_00290A80* s);
extern "C" int func_001E5548(unsigned int, int);
extern "C" int func_001E8180(void* p, unsigned int key, int* out, int req);
extern "C" void func_002913C0(Obj_00290A80* self, int p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_002914F8(Obj_00290A80* self, int v);
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" int func_001E8398(void* p, unsigned int key, int* out, int req);
extern "C" void func_002605F8(Sub_00290A80* s);
extern "C" void func_002606A0(Sub_00290A80* s);
extern "C" void func_002606C0(Sub_00290A80* s, int a, int b, int c, int d, int e);
extern "C" int func_001E7EB0(void* p, unsigned int key, float* out, int req);
extern "C" void func_00291378(Obj_00290A80* self);
extern "C" Lnk_00290A80* func_00185578(void*, unsigned int);
extern "C" void func_00239158(void* p, int a, float f);
extern "C" void func_00239178(void* p, int a, float f);
extern "C" void func_00260628(Sub_00290A80* s);
extern "C" void func_00260638(Sub_00290A80* s);

struct Obj_00290A80 {
    char pad0[0xC];
    void* mC;
    char pad10[0x1C - 0x10];
    unsigned int m1C;
    int m20;
    void* m24;
    char pad28[0x30 - 0x28];
    Sub_00290A80 m_sub[4];
    int Cmd(unsigned int id, void* params, void* script);
};

int Obj_00290A80::Cmd(unsigned int id, void* params, void* script)
{
    switch (id) {
    case 0xEA6D0EFD: {
        if (func_001E8708(params, 0x6D941203)) {
            func_00260A18(&m_sub[0]);
            func_00260A18(&m_sub[1]);
            func_00260A18(&m_sub[2]);
            func_00260A18(&m_sub[3]);
        }
        int p = func_001E5548(0x5ADB96D4, 1);
        func_001E8180(params, 0xD095379C, &p, 0);
        func_002913C0(this, p);
        break;
    }
    case 0x7E92670C: {
        if (m24) {
            func_001E6AE8(m24, 3);
            m24 = 0;
        }
        int a = 0;
        if (func_001E8180(params, 0x647FACC2, &a, 0))
            func_002914F8(this, a);
        int b = 0;
        func_001E7DE8(params, 0x2BFD3D35, &b, 0);
        int c = 0;
        int d = 0;
        func_001E8398(params, 0x4F1A0B01, &c, 1);
        func_001E8398(params, 0xD6135ABB, &d, 1);
        int e = 0;
        func_001E8398(params, 0x7321A8D6, &e, 0);
        if (m1C != (unsigned int)e) {
            m1C = e;
            int f0 = func_001E8708(params, 0x1304E677);
            int f1 = func_001E8708(params, 0x08FE31ED);
            int f2 = func_001E8708(params, 0xBBDB0F78);
            Sub_00290A80* s;
            switch (m1C) {
            case 0x0AC90769:
            case 0xEF24413B:
                s = &m_sub[0];
                break;
            case 0x255ED86F:
            case 0x8D10119D:
                s = &m_sub[1];
                break;
            case 0xA549B57B:
                s = &m_sub[2];
                break;
            case 0x3506CE64:
                s = &m_sub[3];
                break;
            case 0x00000000:
            default:
                return 1;
            }
            if (f2)
                func_002605F8(s);
            func_002606A0(s);
            func_002606C0(s, c, d, b, f0, f1);
        }
        break;
    }
    case 0x7A0DCD4B:
        if (m1C) {
            float v0;
            float v1;
            float v2;
            float v3;
            float v4;
            float v5;
            v3 = 1.0f;
            v4 = 1.0f;
            v5 = 1.0f;
            v0 = 0.0f;
            v1 = 0.0f;
            v2 = 0.0f;
            func_001E7EB0(params, 0x3A4E9413, &v0, 0);
            func_001E7EB0(params, 0x0B4CECC1, &v1, 0);
            func_001E7EB0(params, 0xEB9ECABB, &v2, 0);
            func_001E7EB0(params, 0x4C074698, &v3, 0);
            func_001E7EB0(params, 0x24EBF718, &v4, 0);
            func_001E7EB0(params, 0x94DBBD1C, &v5, 0);
            Sub_00290A80* s;
            switch (m1C) {
            default:
                s = 0;
                break;
            case 0x255ED86F:
            case 0x8D10119D:
                s = &m_sub[1];
                break;
            case 0xA549B57B:
                s = &m_sub[2];
                break;
            case 0x3506CE64:
                s = &m_sub[3];
                break;
            case 0x0AC90769:
            case 0xEF24413B:
                s = &m_sub[0];
                break;
            }
            s->m34 *= v3;
            s->m34 += v0;
            if (s->m34 < 0.0f)
                s->m34 = 0.0f;
            s->m3C *= v4;
            s->m3C += v1 * Sign_00290A80(s->m3C);
            s->m40 *= v5;
            s->m40 += v2 * Sign_00290A80(s->m40);
        }
        break;
    case 0xE553A5B8:
        func_00291378(this);
        break;
    case 0x6CC475B7:
        m20 = 1;
        break;
    case 0x78E669AB: {
        Lnk_00290A80* l = func_00185578(mC, 0xD262802F);
        func_00239158(l->m1C, 0, 0.0f);
        func_00239178(l->m1C, 0, 0.0f);
        func_00260628(&m_sub[0]);
        func_00260628(&m_sub[1]);
        func_00260628(&m_sub[2]);
        func_00260628(&m_sub[3]);
        break;
    }
    case 0x73727701:
        func_00260638(&m_sub[0]);
        func_00260638(&m_sub[1]);
        func_00260638(&m_sub[2]);
        func_00260638(&m_sub[3]);
        break;
    default:
        return 2;
    }
    return 1;
}
