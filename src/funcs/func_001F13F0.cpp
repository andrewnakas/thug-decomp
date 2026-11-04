struct Obj_001F13F0 {
    char pad[0x1f0];
    int m_val;
    void Set(int v);
};

void Obj_001F13F0::Set(int v)
{
    m_val = v;
}
