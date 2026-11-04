struct Rgba158888 {
    unsigned char r, g, b, a;
};

struct Obj158888 {
    char m_pad[0x220];
    Rgba158888* m220;
    void SetA(int i, unsigned char v);
};

void Obj158888::SetA(int i, unsigned char v)
{
    m220[i].a = v >> 1;
}
