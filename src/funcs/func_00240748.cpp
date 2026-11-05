struct Mgr_00240748 {
    char pad[0x54];
    void* m_54;
    void SetFlag(unsigned int name, int remove, int on);
};

extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

void Mgr_00240748::SetFlag(unsigned int name, int remove, int on)
{
    if (remove) {
        func_001E6B90(m_54, name);
    } else if (on) {
        func_001E7200(m_54, name, 1);
    } else {
        func_001E7200(m_54, name, 0);
    }
}
