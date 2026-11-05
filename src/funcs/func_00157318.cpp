struct E {
    unsigned char r, g, b, a;
};

struct Obj00157318 {
    char pad[0x21c];
    E* m_arr;
    void Set(int i, unsigned char v);
};

void Obj00157318::Set(int i, unsigned char v)
{
    m_arr[i].b = v;
}
