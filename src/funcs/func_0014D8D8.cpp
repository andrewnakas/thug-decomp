struct Rgba_0014D8D8 {
    unsigned char r, g, b, a;
};

struct Ins_0014D8D8 {
    char pad[0x60];
    int m60;
};

extern "C" void func_00172780(Ins_0014D8D8* p, int a, int b, unsigned int c);

struct Ent_0014D8D8 {
    char pad[0x18];
    Ins_0014D8D8* m18;
    bool SetPartColor(int a, int b, Rgba_0014D8D8* c);
};

bool Ent_0014D8D8::SetPartColor(int a, int b, Rgba_0014D8D8* c)
{
    if (!m18)
        return false;
    if ((m18->m60 >> 4) & 1)
        func_00172780(m18, a, b, *(unsigned int*)c);
    return true;
}
