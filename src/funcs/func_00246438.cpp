struct Item_00246438 {
    char pad[0x20];
    void* m_20;
    bool Check();
};

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool Item_00246438::Check()
{
    int a = 0;
    int b;
    func_001E7DE8(m_20, 0x129DAA10, &a, 0);
    func_001E7DE8(m_20, 0x696FE0AB, &b, 1);
    return a >= b;
}
