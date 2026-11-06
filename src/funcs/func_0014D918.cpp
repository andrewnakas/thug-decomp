struct Pod_0014D918 {
    unsigned char r, g, b, a;
};

struct Col_0014D918 {
    Pod_0014D918 c;
    Col_0014D918(const Pod_0014D918& p) : c(p) {}
    Col_0014D918(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        c.r = r;
        c.g = g;
        c.b = b;
        c.a = a;
    }
    Col_0014D918(const Col_0014D918& o);
};

struct Ins_0014D918 {
    char pad[0x60];
    int m60;
};

extern "C" unsigned int func_001727F8(Ins_0014D918* p, int a, int b);

struct Ent_0014D918 {
    char pad[0x18];
    Ins_0014D918* m18;
    Col_0014D918 GetPartColor(int a, int b);
};

Col_0014D918 Ent_0014D918::GetPartColor(int a, int b)
{
    if (m18 && ((m18->m60 >> 4) & 1)) {
        unsigned int v = func_001727F8(m18, a, b);
        return Col_0014D918(*(Pod_0014D918*)&v);
    }
    return Col_0014D918(0x80, 0x80, 0x80, 0x80);
}
