struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00158820 {
    char pad[0x21c];
    Rgba* m_colors;
    void Set(int i, unsigned char v);
};

void Obj00158820::Set(int i, unsigned char v)
{
    m_colors[i].a = v >> 1;
}
