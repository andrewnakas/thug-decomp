struct Elem_001726C0 {
    char data[0x40];
};

class Obj_001726C0 {
public:
    char pad[0x40];
    Elem_001726C0* m_items;
    char pad44[0x24];
    int m_index;
    char pad6C[0xD];
    char m_79;
    Elem_001726C0* Get();
};

Elem_001726C0* Obj_001726C0::Get()
{
    Elem_001726C0* p = m_items;
    if (!m_79) p += m_index;
    return p;
}
