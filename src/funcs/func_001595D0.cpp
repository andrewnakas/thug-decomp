struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj001595D0 {
    char pad[0x238];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj001595D0::Set(int i, unsigned char v)
{
    m_colors[i].b = v;
}
