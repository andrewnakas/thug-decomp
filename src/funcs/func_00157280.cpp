struct E {
    unsigned char r, g, b, a;
};

struct Obj00157280 {
    char pad[0x218];
    E* m_arr;
    void Set(int i, unsigned char v);
};

void Obj00157280::Set(int i, unsigned char v)
{
    m_arr[i].r = v;
}
