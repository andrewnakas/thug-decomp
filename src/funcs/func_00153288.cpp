struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00153288 {
    char pad[0x220];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj00153288::Set(int i, unsigned char v)
{
    m_colors[i].a = v >> 1;
}
