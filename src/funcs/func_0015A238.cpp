struct E {
    unsigned char r, g, b, a;
};

struct Obj0015A238 {
    char pad[0x228];
    E* m_arr;
    void Set(int i, unsigned char v);
};

void Obj0015A238::Set(int i, unsigned char v)
{
    m_arr[i].b = v;
}
