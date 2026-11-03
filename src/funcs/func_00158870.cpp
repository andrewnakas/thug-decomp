struct Rgba158870 {
    unsigned char r, g, b, a;
};

struct Obj158870 {
    char m_pad[0x220];
    Rgba158870* m220;
    void SetB(int i, unsigned char v);
};

void Obj158870::SetB(int i, unsigned char v)
{
    m220[i].b = v;
}
