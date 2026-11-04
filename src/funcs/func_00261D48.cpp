extern "C" bool func_001E8180(void* params, unsigned int name, void* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_0011FAB8(void* table, int key, int a);
extern "C" void func_001E6B30(void* s);
extern "C" void func_001E6AC8(void* s, int src);

struct Obj_00261D48 {
    int m_0;
    char m_4[0x58];
    char m_5C[4];

    void Load(unsigned int name, void* params);
};

void Obj_00261D48::Load(unsigned int name, void* params)
{
    void* sub = 0;
    func_001E8180(params, name, &sub, 0);
    if (!sub)
        return;
    int value = 0;
    if (func_001E8180(sub, 0x554C7D6F, &value, 0))
        func_0011FAB8(m_4, value, 1);
    value = 0;
    func_001E8180(sub, 0x3476CEA8, &value, 0);
    func_001E6B30(m_5C);
    func_001E6AC8(m_5C, value);
    int flag = 1;
    func_001E7DE8(sub, 0x95388A60, &flag, 0);
}
