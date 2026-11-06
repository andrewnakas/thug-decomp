struct Pod_0014D7D0 {
    unsigned char r, g, b, a;
};

struct Col_0014D7D0 {
    Pod_0014D7D0 c;
    Col_0014D7D0(const Pod_0014D7D0& p) : c(p) {}
    Col_0014D7D0(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        c.r = r;
        c.g = g;
        c.b = b;
        c.a = a;
    }
    Col_0014D7D0(const Col_0014D7D0& o);
};

extern "C" int func_00170548(void* p);
extern "C" unsigned int func_001707A0(void* p);
extern "C" unsigned int func_00172778(void* p);

struct Ent_0014D7D0 {
    char pad[0x18];
    void* m18;
    int m1C;
    void* m20;
    Col_0014D7D0 GetColor();
};

Col_0014D7D0 Ent_0014D7D0::GetColor()
{
    if (m20 && func_00170548(m20)) {
        unsigned int v = func_001707A0(m20);
        return Col_0014D7D0(*(Pod_0014D7D0*)&v);
    }
    if (m18) {
        unsigned int v = func_00172778(m18);
        return Col_0014D7D0(*(Pod_0014D7D0*)&v);
    }
    return Col_0014D7D0(0x80, 0x80, 0x80, 0x80);
}
