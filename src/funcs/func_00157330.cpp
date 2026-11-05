struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj00157330 {
    char pad[0x21c];
    Rgba* m_colors;
    void Set(int i, unsigned char v);
};

void Obj00157330::Set(int i, unsigned char v)
{
    m_colors[i].a = v >> 1;
}
