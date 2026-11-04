struct Rgba {
    unsigned char r, g, b, a;
};

struct Obj001562F8 {
    char pad[0x218];
    Rgba m_colors[1];
    void Set(int i, unsigned char v);
};

void Obj001562F8::Set(int i, unsigned char v)
{
    m_colors[i].r = v;
}
