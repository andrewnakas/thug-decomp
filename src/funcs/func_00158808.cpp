struct E {
    unsigned char r, g, b, a;
};

struct Obj00158808 {
    char pad[0x21c];
    E* m_arr;
    void Set(int i, unsigned char v);
};

void Obj00158808::Set(int i, unsigned char v)
{
    m_arr[i].b = v;
}
