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
extern "C" void* func_0014C1C8(Arg_0014D470* a);
extern "C" void* func_00170C30(void* p, void* dst, void* n);
extern "C" void* func_00170E08(void* p, void* n, int one);

class C_0014D470 : public B_0014D470 {
public:
    void* m18;
    int m1C;
    void* m20;
    Mat_0014D470 m30;
    void* m70;
    virtual void v0();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    C_0014D470* Clone2(int a, Arg_0014D470* arg);
};

C_0014D470* C_0014D470::Clone2(int a, Arg_0014D470* arg)
{
    void* h;
    if (arg) {
        h = func_0014C1C8(arg);
    } else {
        h = 0;
    }
    C_0014D470* c = new C_0014D470(*this);
    if (c) {
        if (m20) {
            if (a) {
                c->m20 = func_00170C30(m20, &c->m30, h);
            } else {
                c->m20 = func_00170E08(m20, h, 1);
            }
        }
    }
    return c;
}
