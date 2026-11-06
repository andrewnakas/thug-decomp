extern "C" void func_001EE4D8(void* p, int a);

struct C_0024FE88 {
    char m_pad[0x14];
    void* m14;
    bool Release();
};

bool C_0024FE88::Release()
{
    if (!m14) return false;
    func_001EE4D8(m14, 3);
    m14 = 0;
    return true;
}
