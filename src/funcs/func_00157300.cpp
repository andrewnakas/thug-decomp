struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00157300 {
    char pad[0x21c];
    Rgba* m_colors;
    void Set(int i, unsigned char v);
};

void Obj00157300::Set(int i, unsigned char v)
{
    m_colors[i].g = v;
}
