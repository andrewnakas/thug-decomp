struct Item_00244E90 {
    char pad[0x54];
    int m_54;
    char pad58[0xA0 - 0x58];
    int m_A0;
    bool Check();
};

extern void* D_0038FC78;
extern void* D_00392068;
extern "C" void* func_0022DD38(void* self);
extern "C" bool func_002A39F8(void* a);

bool Item_00244E90::Check()
{
    void* net = D_00392068;
    if (!func_0022DD38(D_0038FC78)) {
        return true;
    }
    if (!func_002A39F8(net)) {
        return true;
    }
    if (m_A0) {
        return false;
    }
    return m_54 < 1;
}
