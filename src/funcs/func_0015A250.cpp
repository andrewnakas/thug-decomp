struct E {
    unsigned char r, g, b, a;
};

struct Obj0015A250 {
    char pad[0x228];
    E* m_arr;
    void Set(int i, unsigned char v);
};

void Obj0015A250::Set(int i, unsigned char v)
{
    m_arr[i].a = v >> 1;
}
