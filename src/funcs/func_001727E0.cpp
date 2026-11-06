class Obj_001727E0 {
public:
    char pad[0x64];
    int* m_items;
    void SetItem(int i, int v);
};

void Obj_001727E0::SetItem(int i, int v)
{
    m_items[i] = v;
}
