struct Rgba15A180 {
    unsigned char r, g, b, a;
};

struct Obj15A180 {
    char m_pad[0x220];
    Rgba15A180* m220;
    void SetA(int i, unsigned char v);
};

void Obj15A180::SetA(int i, unsigned char v)
{
    m220[i].a = v >> 1;
}
