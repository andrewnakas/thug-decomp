struct Rgba_00136EA8 {
    unsigned char r, g, b, a;
    Rgba_00136EA8(const Rgba_00136EA8& o) { *this = o; }
};

struct Owner_00136EA8 {
    char pad[0x1C];
    Rgba_00136EA8 m1C;
    void SetColor(Rgba_00136EA8 c) { m1C = c; }
};

extern "C" Owner_00136EA8* func_001365E8(int id);

struct Light_00136EA8 {
    char pad[0x18];
    int m18;
    Rgba_00136EA8 m1C;
    void SetColor(Rgba_00136EA8 c);
};

void Light_00136EA8::SetColor(Rgba_00136EA8 c)
{
    m1C = c;
    Owner_00136EA8* o = func_001365E8(m18);
    if (o)
        o->SetColor(c);
}
