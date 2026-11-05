struct E {
    unsigned char r, g, b, a;
};

struct Obj001587B8 {
    char pad[0x218];
    E* m_arr;
    void Set(int i, unsigned char v);
};

void Obj001587B8::Set(int i, unsigned char v)
{
    m_arr[i].a = v >> 1;
}
