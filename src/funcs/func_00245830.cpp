struct Item_00245830 {
    char pad[0x20];
    void* m_20;
    char pad24[0x5C - 0x24];
    int m_5C;
    int m_60;
    bool Check();
};

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool Item_00245830::Check()
{
    int v = m_5C;
    func_001E7DE8(m_20, 0x1171A555, &v, 0);
    if (!v) {
        return false;
    }
    return m_60 >= v;
}
