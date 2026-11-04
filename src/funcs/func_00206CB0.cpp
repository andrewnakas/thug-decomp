struct Array_00206CB0;

extern "C" void* func_00122CF8(unsigned int size);
extern "C" Array_00206CB0* func_001E8DD0(void* mem);
extern "C" void func_001E8E98(Array_00206CB0* a, int size, int type);
extern "C" void func_001E90A8(Array_00206CB0* a, int i, int value);
extern "C" int func_001F4FF0(void* src, int i);
extern "C" void func_001E7720(void* params, unsigned int name, Array_00206CB0* a);

struct Obj_00206CB0 {
    char pad0[0x2EC];
    void* m_2EC;

    void WriteArray(void* params);
};

void Obj_00206CB0::WriteArray(void* params)
{
    Array_00206CB0* a = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(a, 0x46, 1);
    for (int i = 0; i < 0x46; i++)
        func_001E90A8(a, i, func_001F4FF0(m_2EC, i));
    func_001E7720(params, 0x44B66A9F, a);
}
