struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00155610 {
    char pad[0x224];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00155610::Set(int i, unsigned char v)
{
    m_colors[i].a = v >> 1;
}
