typedef int qword_0028ED58 __attribute__((mode(TI)));

extern "C" void func_00183C98(void* p, void* r);

union Vec_0028ED58 {
    qword_0028ED58 q;
    float f[4];
    Vec_0028ED58(const Vec_0028ED58& o) : q(o.q) {}
};

struct Ref_0028ED58 {
    void* p;
    int m4;
    int m8;
    Ref_0028ED58(const Ref_0028ED58& o)
    {
        m4 = 0;
        m8 = 0;
        p = o.p;
        if (p)
            func_00183C98(p, this);
    }
};

struct A_0028ED58 {
    Vec_0028ED58 m0;
    Vec_0028ED58 m10;
    int m20;
    A_0028ED58(const A_0028ED58& o) : m0(o.m0), m10(o.m10), m20(o.m20) {}
};

struct B_0028ED58 {
    A_0028ED58 m0;
    float m30;
    unsigned short m34;
    unsigned short m36;
    unsigned short m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    int m50;
    int m54;
    unsigned char m58;
    unsigned char m59;
    B_0028ED58(const B_0028ED58& o)
        : m0(o.m0), m30(o.m30), m34(o.m34), m36(o.m36), m38(o.m38), m3C(o.m3C), m40(o.m40), m44(o.m44),
          m48(o.m48), m4C(o.m4C), m50(o.m50), m54(o.m54), m58(o.m58), m59(o.m59)
    {
    }
};

struct Obj_0028ED58 {
    A_0028ED58 m0;
    B_0028ED58 m30;
    float m90;
    Vec_0028ED58 mA0;
    Vec_0028ED58 mB0;
    Ref_0028ED58 mC0;
    int mCC;
    int mD0;
    int mD4;
    Obj_0028ED58(const Obj_0028ED58& o);
};

Obj_0028ED58::Obj_0028ED58(const Obj_0028ED58& o)
    : m0(o.m0), m30(o.m30), m90(o.m90), mA0(o.mA0), mB0(o.mB0), mC0(o.mC0), mCC(o.mCC), mD0(o.mD0), mD4(o.mD4)
{
}
