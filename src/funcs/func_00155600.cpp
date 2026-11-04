struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00155600 {
    char pad[0x224];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00155600::Set(int i, unsigned char v)
{
    m_colors[i].b = v;
}
