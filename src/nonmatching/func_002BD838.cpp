/* fuzzy: 97.5 */
/* sym: __12Box_002BD838iiiiii = 0x002BAA28 */
typedef int qword __attribute__((mode(TI)));

struct Vec_002BD838 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
    Vec_002BD838() {}
    float Y() const { return y; }
    Vec_002BD838(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_002BD838 operator+(const Vec_002BD838& a, const Vec_002BD838& b)
{
    return Vec_002BD838(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

struct Box_002BD838;
extern "C" unsigned char* func_002BAA48(Box_002BD838* b, int idx);

struct Box_002BD838 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002BD838(int a = 0, int b = 0, int c = 0, int e = 0, int f = 0, int g = 0);
    unsigned char& operator[](int i) { return *func_002BAA48(this, i); }
    void SetDims(unsigned char nw, unsigned char nh, unsigned char nd)
    {
        w = nw;
        h = nh;
        d = nd;
    }
    void SetPos(unsigned char nx, signed char ny, unsigned char nz)
    {
        x = nx;
        y = ny;
        z = nz;
    }
};

extern "C" void func_00183CB8(int obj, int* ref);

struct Feeler_002BD838 {
    Vec_002BD838 m_start;
    Vec_002BD838 m_end;
    char pad20[0xA0 - 0x20];
    Vec_002BD838 m_point;
    Vec_002BD838 m_normal;
    struct Ref {
        int p;
        void Release()
        {
            if (p) {
                func_00183CB8(p, &p);
                p = 0;
            }
        }
    } m_ref;
    char padC4[0xE0 - 0xC4];
    const Vec_002BD838& Point() const { return m_point; }
    ~Feeler_002BD838()
    {
        Ref* h = &m_ref;
        h->Release();
    }
};

struct List_002BD838 {
    int m0;
    int pad[3];
};

extern const float D_00392610;
extern const float D_00392618;

struct Park_002BD838;
extern "C" void func_00209240(Feeler_002BD838* f);
extern "C" void func_00209360(Feeler_002BD838* f, const Vec_002BD838& v);
extern "C" void func_00209370(Feeler_002BD838* f, const Vec_002BD838& v);
extern "C" int func_002093E8(Feeler_002BD838* f, int a, int b);
extern "C" void func_002BA878(void* b);
extern "C" int func_002BA650(void* b, int type, int n);
extern "C" void func_002BA418(void* b, Vec_002BD838* pos, int a, Box_002BD838* box, int type, int c, int d);
extern "C" void func_002B8218(void* b, void* a);
extern "C" int func_002BFC50(Park_002BD838* p, Box_002BD838 b, int c);
extern "C" void* func_002BF5C0(Park_002BD838* p, Box_002BD838 b, int a, int c, int d);
extern "C" List_002BD838* func_002BC630(List_002BD838* l, void* r);
extern "C" void func_002BC640(List_002BD838* l, int f);
extern "C" void* func_002BC690(List_002BD838* l);
extern "C" void* func_002BC5A0(void* n);
extern "C" Box_002BD838* func_002BAB80(void* p);
extern "C" Vec_002BD838 func_002C02B0(Park_002BD838* p, Box_002BD838* b, Vec_002BD838* out);

struct Park_002BD838 {
    void* m0;
    char pad4[0x80 - 4];
    void* m80;
    char pad84[0x352C - 0x84];
    Box_002BD838 m352C;
    void Fill();
};

void Park_002BD838::Fill()
{
    func_002BA878(m0);
    for (int i = 0; i < 18; i++) {
        Box_002BD838 b;
        int type = 1;
        b = m352C;
        b.SetPos(b.x + (b.w >> 1), 0, b.z + (b.d >> 1));
        b.SetDims(1, 1, 1);
        int n = 1;
        if (i == 1) {
            b.SetPos(b.x + 1, 0, b.z);
            type = 2;
        }
        if (i == 2) {
            b.SetPos(b.x - 2, 0, b.z + 2);
            type = 5;
        }
        if (i == 3) {
            b.SetPos(b.x, 0, b.z + 2);
            type = 6;
        }
        if (i == 4) {
            b.SetPos(b.x + 2, 0, b.z + 2);
            type = 7;
        }
        if (i == 5) {
            b.SetPos(b.x + 4, 0, b.z + 2);
            type = 8;
        }
        if (i >= 6 && i < 12) {
            n = 6;
            b.SetPos(b.x - 9 + i, 0, b.z - 2);
            type = 3;
        }
        int flag = 0;
        if (i >= 12 && i < 18) {
            flag = 1;
            n = 6;
            b.SetPos(b.x - 15 + i, 0, b.z - 3);
            type = 4;
        }
        if (func_002BA650(m0, type, n)) {
            b.SetPos(b.x, func_002BFC50(this, b, 0), b.z);
            List_002BD838 l;
            func_002BC630(&l, func_002BF5C0(this, b, 0, 0, 0));
            if (l.m0) {
                unsigned char& p = b[1];
                int y = b.y;
                y += func_002BAB80(func_002BC5A0(func_002BC690(&l)))->h;
                p = y;
            }
            func_002BC640(&l, 2);
            Vec_002BD838 pos = func_002C02B0(this, &b, 0);
            pos.x += D_00392610 * 0.5f;
            pos.z += D_00392618 * 0.5f;
            Feeler_002BD838 f;
            func_00209240(&f);
            func_00209360(&f, pos + Vec_002BD838(0.0f, 10000.0f, 0.0f, 1.0f));
            func_00209370(&f, pos + Vec_002BD838(0.0f, -1000.0f, 0.0f, 1.0f));
            pos.y = func_002093E8(&f, 1, 0) ? f.Point().Y() : pos.y;
            func_002BA418(m0, &pos, 0, &b, type, 1, flag);
        }
    }
    func_002B8218(m0, m80);
}
