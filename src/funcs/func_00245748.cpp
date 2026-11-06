struct Item_00245748 {
    char pad[0x24];
    void* m_24;
    bool Check(unsigned int name, int value);
};

extern "C" int func_001E8618(void* params, unsigned int name);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool Item_00245748::Check(unsigned int name, int value)
{
    int v;
    if (func_001E8618(m_24, name)) {
        func_001E7DE8(m_24, name, &v, 1);
        return value == v;
    }
    return false;
}
