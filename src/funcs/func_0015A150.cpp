struct Rgba15A150 {
    unsigned char r, g, b, a;
};

struct Obj15A150 {
    char m_pad[0x220];
    Rgba15A150* m220;
    void SetG(int i, unsigned char v);
};

void Obj15A150::SetG(int i, unsigned char v)
{
    m220[i].g = v;
}
