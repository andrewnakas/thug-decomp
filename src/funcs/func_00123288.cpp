extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* mem);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E90F8(void* arr, int i, int v);
extern "C" void func_001E7720(void* s, unsigned int id, void* arr);
extern "C" void func_001E70C0(void* s, unsigned int id, void* v);
extern "C" void func_00122688(void* sub, void* s);

struct C_00123288 {
    int m0;
    int m4;
    char m8[0x38];
    int m40[0x1108];
    char m4460[4];
    void Write(void* s);
};

void C_00123288::Write(void* s)
{
    int i;
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    func_001E8E98(arr, 0x1108, 0xD);
    int* p = m40;
    for (i = 0; i < 0x1108; i++) {
        func_001E90F8(arr, i, *p);
        p++;
    }
    func_001E7720(s, 0x99790D96, arr);
    func_001E70C0(s, 0xA7E7A264, m4460);
    func_00122688(m8, s);
}
