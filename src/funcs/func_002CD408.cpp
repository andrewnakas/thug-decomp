struct Color_002CD408 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
};

extern "C" void func_002BAA28(Color_002CD408* c, int a, int b, int d, int e, int f, int g);

struct Obj_002CD408 {
    unsigned char m0;
    Color_002CD408 m1;
    unsigned char m7;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    char padB;
    int mC;
    int m10;
    int m14;
    Obj_002CD408* Init();
};

Obj_002CD408* Obj_002CD408::Init()
{
    Color_002CD408* c = &m1;
    func_002BAA28(c, 0, 0, 0, 0, 0, 0);
    mC = 0;
    m8 = 0xFF;
    m7 = 0xFF;
    mA = 0;
    m9 = 0;
    m14 = 0;
    c->m0 = 0;
    c->m1 = 0;
    c->m2 = 0;
    c->m3 = 0;
    c->m4 = 0;
    c->m5 = 0;
    m10 = 0;
    return this;
}
