struct Obj_0023AC98 {
    char pad[0x1A8];
    char m_1A8[0x9C4];
    char padB6C[0x1530 - 0xB6C];
    int m_1530;
    int m_1534;
    int m_1538;
    void Reset();
};

extern "C" void func_0023ACE0(Obj_0023AC98* self);

void Obj_0023AC98::Reset()
{
    m_1530 = 0;
    m_1538 = 0;
    for (int i = 0; i < 0x9C4; i++) {
        m_1A8[i] = 0;
    }
    func_0023ACE0(this);
}
