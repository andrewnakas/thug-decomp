struct Rgba15A168 {
    unsigned char r, g, b, a;
};

struct Obj15A168 {
    char m_pad[0x220];
    Rgba15A168* m220;
    void SetB(int i, unsigned char v);
};

void Obj15A168::SetB(int i, unsigned char v)
{
    m220[i].b = v;
}
