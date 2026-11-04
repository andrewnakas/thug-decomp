struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj001587A0 {
    char pad[0x218];
    Rgba* m_colors;
    void Set(int i, unsigned char v);
};

void Obj001587A0::Set(int i, unsigned char v)
{
    m_colors[i].b = v;
}
