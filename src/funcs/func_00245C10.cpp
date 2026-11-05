struct Item_00245C10 {
    char pad[0x20];
    void* m_20;
    bool Check();
};

extern "C" int func_001E8708(void* params, unsigned int name);

bool Item_00245C10::Check()
{
    if (func_001E8708(m_20, 0xC8A82B5A) || func_001E8708(m_20, 0xF268C278)) {
        return true;
    }
    return false;
}
