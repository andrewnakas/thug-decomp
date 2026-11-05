struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj001595E0 {
    char pad[0x238];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj001595E0::Set(int i, unsigned char v)
{
    m_colors[i].a = v >> 1;
}
