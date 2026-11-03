typedef int qword __attribute__((mode(TI)));

struct Vec_0014D470 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0014D470 {
    Vec_0014D470 r[4];
    Mat_0014D470() {}
    const Vec_0014D470& operator[](int i) const { return r[i]; }
    Mat_0014D470(const Mat_0014D470& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    void Ident()
    {
        r[0].x = 1.0f; r[0].y = 0.0f; r[0].z = 0.0f; r[0].w = 0.0f;
        r[1].x = 0.0f; r[1].y = 1.0f; r[1].z = 0.0f; r[1].w = 0.0f;
        r[2].x = 0.0f; r[2].y = 0.0f; r[2].z = 1.0f; r[2].w = 0.0f;
        r[3].x = 0.0f; r[3].y = 0.0f; r[3].z = 0.0f; r[3].w = 1.0f;
    }
};

struct Info_0014D470 {
    char pad[0x30];
    int count;
};

struct Geom_0014D470 {
    char pad[0x60];
    int flags;
    char pad64[0x70 - 0x64];
    Info_0014D470* info;
};

struct Arg_0014D470 {
    int m0, m4;
    int m8;
};

struct Empty_0014D470 {
};

class B_0014D470 : public Empty_0014D470 {
public:
    int m4, m8, mC, m10;
    virtual void v0();
};

extern "C" void* func_001046B0(int size);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;
extern "C" void* func_0014C9A8(Arg_0014D470* a);
extern "C" Geom_0014D470* func_001724A8(void* mem, Info_0014D470* info, Mat_0014D470 m, int flag, int k, void* p);
extern "C" Geom_0014D470* func_001723A0(void* mem, Info_0014D470* info, Mat_0014D470 m, int flag);
extern "C" void* func_00172858(Geom_0014D470* g, int i);
extern "C" void func_001727E0(Geom_0014D470* g, int i, void* v);
extern "C" void* func_00172778(Geom_0014D470* g);
extern "C" void func_00172770(Geom_0014D470* g, void* v);

class C_0014D470 : public B_0014D470 {
public:
    Geom_0014D470* m18;
    int m1C;
    int m20;
    Mat_0014D470 m30;
    void* m70;
    virtual void v0();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    C_0014D470* Clone(int a, Arg_0014D470* arg);
};

C_0014D470* C_0014D470::Clone(int a, Arg_0014D470* arg)
{
    C_0014D470* c = new C_0014D470(*this);
    int k = arg->m8;
    Mat_0014D470 m;
    m.Ident();
    c->m70 = func_0014C9A8(arg);
    Info_0014D470* info = m18->info;
    if (k) {
        c->m18 = func_001724A8(func_0010A638(D_00388A70, 0x80, 1, 0), info, m, (m18->flags >> 4) & 1, k, c->m70);
    } else {
        c->m18 = func_001723A0(func_0010A638(D_00388A70, 0x80, 1, 0), info, m, (m18->flags >> 4) & 1);
    }
    if ((m18->flags >> 4) & 1) {
        int n = m18->info->count;
        for (int i = 0; i < n; i++) {
            func_001727E0(c->m18, i, func_00172858(m18, i));
        }
    } else {
        func_00172770(c->m18, func_00172778(m18));
    }
    return c;
}
