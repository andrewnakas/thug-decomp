struct E {
    unsigned char r, g, b, a;
};

struct Obj00159568 {
    char pad[0x228];
    E m_arr[1];
    void Set(int i, unsigned char v);
};

void Obj00159568::Set(int i, unsigned char v)
{
    m_arr[i].r = v;
}
