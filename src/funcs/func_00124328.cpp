typedef int qword __attribute__((mode(TI)));

struct Obj124328;
struct Handle124328;

extern "C" void func_00183C98(Obj124328* o, Handle124328* h);
extern "C" void func_00183CB8(Obj124328* o, Handle124328* h);

struct Handle124328 {
    Obj124328* m_obj;
    Handle124328* m_prev;
    Handle124328* m_next;
    Handle124328(Obj124328* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle124328(const Handle124328& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle124328()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

struct Range124328 {
    int m0;
    float a;
    float b;
    int mC;
    Range124328();
};

struct Vec124328 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Color124328 {
    unsigned char r, g, b, a;
};

struct Pair124328 {
    float a;
    float b;
};

extern "C" int func_001E8998(void* params, unsigned int id, Range124328* out, int req);
extern "C" int func_001E7FA8(void* params, unsigned int id, Vec124328* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" bool func_001E8708(void* params, unsigned int id);
extern "C" void* func_0012E438(void* o, void* params, unsigned int id);
extern "C" Handle124328 func_0012DB48(void* o, void* x, int flag);
extern "C" void func_0012DA10(void* o, const Handle124328& a, const Handle124328& b, int flag);
extern "C" void func_003315B8(void* p, int c, int n);

struct C_00124328 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
    void* m10;
    void Init(void* params);
};

extern "C" void func_00123A18(C_00124328* self, float a, float b, int f);
extern "C" void func_00123AE8(C_00124328* self, Vec124328* v, int f);
extern "C" void func_00123C40(C_00124328* self, float a, float b, int f);
extern "C" int func_00125A10(C_00124328* self, void* params, unsigned int id, float* a, float* b);
extern "C" void func_00123CD8(C_00124328* self, float a, float b);
extern "C" int func_00125B78(C_00124328* self, void* params, unsigned int id, Color124328* c);
extern "C" void func_00123FE0(C_00124328* self, const Color124328& c, int f);
extern "C" void func_001240C0(C_00124328* self, float f);
extern "C" void func_00184000(C_00124328* self, unsigned int a, unsigned int b);
extern "C" void func_00184050(C_00124328* self, unsigned int a);
extern "C" void func_001240D8(C_00124328* self, int a);
extern "C" void func_00184218(C_00124328* self, void* params);

void C_00124328::Init(void* params)
{
    void* o = m10;
    Range124328 r1;
    if (func_001E8998(params, 0x7F261953, &r1, 0))
        func_00123A18(this, r1.a, r1.b, 1);
    Vec124328 v;
    if (func_001E7FA8(params, 0x4B491900, &v, 0)) {
        v.w = 1.0f;
        func_00123AE8(this, &v, 1);
    }
    Range124328 r2;
    if (func_001E8998(params, 0x34A68574, &r2, 0))
        func_00123C40(this, r2.a, r2.b, 1);
    void* x = func_0012E438(o, params, 0xC2719FB0);
    if (x) {
        Handle124328 h(func_0012DB48(o, x, 0).m_obj);
        func_0012DA10(o, h, Handle124328((Obj124328*)this), 1);
    }
    Pair124328 p;
    func_003315B8(&p, 0, 8);
    if (func_00125A10(this, params, 0x8B60022F, &p.a, &p.b))
        func_00123CD8(this, p.a, p.b);
    Color124328 c;
    if (func_00125B78(this, params, 0x3F6BCDBA, &c))
        func_00123FE0(this, Color124328(c), 1);
    float f;
    if (func_001E7EB0(params, 0x57710F31, &f, 0))
        func_001240C0(this, f);
    if (func_001E8708(params, 0x1D944426))
        func_00184000(this, 0, 0xF33A3321);
    else if (func_001E8708(params, 0x5CDECF29))
        func_00184050(this, 0xF33A3321);
    unsigned int id;
    if (func_001E8398(params, 0xA2A5DEFE, &id, 0))
        func_00184000(this, 0x9494A525, id);
    if (func_001E8708(params, 0xFF85D4D7))
        func_001240D8(this, 0);
    if (func_001E8708(params, 0xE5D6FE3E))
        mC |= 0x200000;
    else if (func_001E8708(params, 0xD5614A50))
        mC &= ~0x200000;
    if (func_001E8708(params, 0x5B6634D4))
        mC |= 0x400000;
    else if (func_001E8708(params, 0xB60D1F35))
        mC = (mC & ~0x400000) | 0x1000;
    func_00184218(this, params);
}
