typedef int qword __attribute__((mode(TI)));

struct Vec_0019D498 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
};

struct Mat_0019D498 {
    Vec_0019D498 r[4];
    void Set(const Vec_0019D498& a, const Vec_0019D498& b, const Vec_0019D498& c, const Vec_0019D498& d)
    {
        r[0] = a;
        r[1] = b;
        r[2] = c;
        r[3] = d;
    }
};

struct Owner_0019D498 {
    char pad0[0x50];
    Vec_0019D498 m50;
    char pad60[0x70 - 0x60];
    Mat_0019D498 m70;
    char padB0[0xC0 - 0xB0];
    Mat_0019D498 mC0;
};

struct Obj_0019D498 {
    char pad0[0xC];
    Owner_0019D498* mC;
    char pad10[0x50 - 0x10];
    Vec_0019D498 m50;
    Vec_0019D498 m60;
    Vec_0019D498 m70;
    Vec_0019D498 m80;
    Vec_0019D498 m90;
    void Fn();
};

void Obj_0019D498::Fn()
{
    m50.w = 1.0f;
    m60.w = 0.0f;
    m70.w = 0.0f;
    m80.w = 0.0f;
    mC->m50 = m50;
    mC->m70.Set(m60, m70, m80, m90);
    mC->mC0.Set(m60, m70, m80, m90);
}
