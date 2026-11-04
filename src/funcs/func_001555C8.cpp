struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj001555C8 {
    char pad[0x218];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj001555C8::Set(int i, unsigned char v)
{
    m_colors[i].a = v >> 1;
}
