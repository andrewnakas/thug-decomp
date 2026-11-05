struct E {
    unsigned char r, g, b, a;
};

struct Obj0015A1A0 {
    char pad[0x224];
    E* m_arr;
    void Set(int i, unsigned char v);
};

void Obj0015A1A0::Set(int i, unsigned char v)
{
    m_arr[i].r = v;
}
