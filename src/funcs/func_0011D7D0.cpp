struct Elem11D7D0 {
    char pad[0x10];
    int m10;
    char pad2[0x1C];
};

struct Obj11D7D0 {
    char pad[0x18];
    Elem11D7D0* m_items;
    int Get(int i) const;
};

int Obj11D7D0::Get(int i) const
{
    Elem11D7D0* p = m_items;
    p += i;
    return p->m10;
}
