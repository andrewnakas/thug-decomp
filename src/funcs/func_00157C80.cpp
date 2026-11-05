struct E {
    unsigned char r, g, b, a;
};

struct Obj00157C80 {
    char pad[0x228];
    E m_arr[1];
    void Set(int i, unsigned char v);
};

void Obj00157C80::Set(int i, unsigned char v)
{
    m_arr[i].a = v >> 1;
}
