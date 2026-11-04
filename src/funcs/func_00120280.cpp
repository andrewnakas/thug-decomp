typedef int qword __attribute__((mode(TI)));

struct Vec120280 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Mgr120280 {
    char pad[0xF0];
    Vec120280 mF0;
};

extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E89F0(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E8870(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E8180(void* s, unsigned int id, int* out, int req);
extern "C" bool func_001E8618(void* params, unsigned int id);
extern "C" bool func_001E8708(void* params, unsigned int id);
extern "C" void func_0011FE10(void* o, int a);
extern "C" void* func_0011FE18(void* o, unsigned int id);
extern "C" void* func_001200E0(void* o);
extern "C" int func_00123420(void* o);
extern "C" int func_00131288(Vec120280* v, int a);
extern "C" void func_0013EDD0(Mgr120280* m, Vec120280* v);
extern "C" int func_0013F048(Mgr120280* m, void* o, int a, unsigned int b);
extern "C" int func_0011DE78(void* o, int a);
extern void* D_00389520;
extern Mgr120280* D_00389518;
extern void* D_0038951C;

struct C_00120280 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual int V9(unsigned int a);
    virtual int V10(unsigned int a);
    virtual int V11(unsigned int a, bool b);
    virtual int V12(void* params);
    virtual int V13(unsigned int a, unsigned int b, int c);
    virtual int V14(unsigned int a, int b);
    virtual int V15(unsigned int a);
    virtual int V16();
    virtual int V17();
    virtual int V18();
    virtual int V19();
    virtual int V20(unsigned int a);
    virtual int V21();
    virtual int V22();
    virtual int V23(unsigned int a, unsigned int b);
    int Handle(unsigned int id, void* params);
};

extern "C" int func_001842E0(C_00120280* self, unsigned int id, void* params);

int C_00120280::Handle(unsigned int id, void* params)
{
    switch (id) {
    case 0x30E2951D:
        func_0011FE10(D_00389520, 0);
        return 1;
    case 0x53DA94F1: {
        unsigned int a;
        func_001E8398(params, 0xB6F08F39, &a, 1);
        V9(a);
        return 1;
    }
    case 0x681A03AF: {
        unsigned int a;
        int b;
        func_001E8398(params, 0xB6F08F39, &a, 1);
        func_001E7DE8(params, 0, &b, 1);
        V11(a, b != 0);
        return 1;
    }
    case 0xAEE6E915:
        V12(params);
        return 1;
    case 0x18924DA1: {
        unsigned int a;
        unsigned int b;
        int c;
        func_001E8398(params, 0xB6F08F39, &a, 1);
        func_001E8398(params, 0x83418A6A, &b, 1);
        func_001E7DE8(params, 0x318F2BDB, &c, 1);
        V13(a, b, c);
        return 1;
    }
    case 0x3BF41299: {
        unsigned int a;
        int b;
        func_001E8398(params, 0x83418A6A, &a, 1);
        func_001E7DE8(params, 0x318F2BDB, &b, 1);
        V14(a, b);
        return 1;
    }
    case 0xAA42A104: {
        unsigned int a;
        func_001E8398(params, 0xB6F08F39, &a, 1);
        V15(a);
        return 1;
    }
    case 0x9041E901:
        V17();
        return 1;
    case 0x50F1285B: {
        int x = 0;
        if (func_001E89F0(params, 0x812684EF, &x, 0)) {
            Vec120280 v;
            Vec120280 s;
            v.q = D_00389518->mF0.q;
            s.Set(1.0f, 1.0f, 1.0f, 1.0f);
            if (func_00131288(&s, x)) {
                v.x *= s.x;
                v.y *= s.y;
                v.z *= s.z;
                v.w *= s.w;
                func_0013EDD0(D_00389518, &v);
            }
        } else {
            V21();
        }
        return 1;
    }
    case 0x21AEC583:
        if (func_001E8618(params, 0x3F5F5BC2)) {
            unsigned int a;
            func_001E8398(params, 0xB6F08F39, &a, 1);
            V20(a);
        }
        return 1;
    case 0xC0BC8271: {
        int x = 0;
        if (func_001E89F0(params, 0x812684EF, &x, 0)) {
            void* o = func_0011FE18(D_00389520, 0x650FAB6D);
            if (o && func_001E8708(params, 0x3C4D849D))
                func_001E8180(o, 0x1ADE0DD8, &x, 0);
            if (D_0038951C)
                return func_0011DE78(D_0038951C, x);
        } else {
            V19();
        }
        return 1;
    }
    case 0x73AB02BC: {
        int r = 1;
        void* o = func_001200E0(D_00389520);
        if (o) {
            if (func_00123420(o) && D_00389518) {
                int a;
                unsigned int b;
                func_001E8870(params, 0x9FBBDB72, &a, 1);
                b = 0xC4E78E22;
                func_001E8398(params, 0xA01371B1, &b, 0);
                r = func_0013F048(D_00389518, o, a, b);
            }
        }
        return r;
    }
    case 0x6516B484: {
        void* o = func_0011FE18(D_00389520, 0x2457F44D);
        if (o)
            return !func_001E8708(o, 0xB25E39FD);
        return 1;
    }
    case 0xCDEEA636:
        V18();
        return 1;
    case 0xBFF957A9: {
        unsigned int a;
        func_001E8398(params, 0xB6F08F39, &a, 1);
        V10(a);
        return 1;
    }
    case 0x0ECF0248:
        V16();
        return 1;
    case 0xB1C39A54: {
        unsigned int a;
        unsigned int b;
        func_001E8398(params, 0xB6F08F39, &a, 1);
        func_001E8398(params, 0xB990D003, &b, 1);
        V23(a, b);
        return 1;
    }
    case 0xCEFE8478:
        V22();
        return 1;
    }
    return func_001842E0(this, id, params);
}
