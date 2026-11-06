struct Rgba_0014D878 {
    unsigned char r, g, b, a;
    Rgba_0014D878(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_)
    {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

extern "C" void func_00170600(void* p, int a);

class Obj_0014D878 {
public:
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void SetColor(Rgba_0014D878* c);
};

class Ent_0014D878 : public Obj_0014D878 {
public:
    void* m18;
    int m1C;
    void* m20;
    void ResetColor();
};

void Ent_0014D878::ResetColor()
{
    if (m20) {
        func_00170600(m20, 0);
    } else {
        Rgba_0014D878 c(0x80, 0x80, 0x80, 0x80);
        SetColor(&c);
    }
}
