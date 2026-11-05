struct E {
    unsigned char r, g, b, a;
};

struct Obj001587D8 {
    char pad[0x21c];
    E* m_arr;
    void Set(int i, unsigned char v);
};

void Obj001587D8::Set(int i, unsigned char v)
{
    m_arr[i].r = v;
}
