struct E {
    unsigned char r, g, b, a;
};

struct Obj001587F0 {
    char pad[0x21c];
    E* m_arr;
    void Set(int i, unsigned char v);
};

void Obj001587F0::Set(int i, unsigned char v)
{
    m_arr[i].g = v;
}
