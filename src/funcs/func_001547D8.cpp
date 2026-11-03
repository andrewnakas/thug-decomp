struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj001547D8 {
    char pad[0x224];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj001547D8::Set(int i, unsigned char v)
{
    m_colors[i].b = v;
}
