extern "C" void func_001ED1B0();
extern "C" void func_001ED1A0();
extern "C" void* func_001E55B8(unsigned int crc, int a);
extern "C" void* func_001E9378(void* arr, unsigned int i);
extern "C" int func_001E8398(void* s, unsigned int crc, int* out, int req);
extern "C" void func_0022A3F0(int a, int b, int c, int d, int e);

struct Arr_0022A720 {
    char pad0[0xC];
    unsigned int m_size;
};

void Run_0022A720(unsigned int crc, int b, int c)
{
    func_001ED1B0();
    Arr_0022A720* a = (Arr_0022A720*)func_001E55B8(0xC472ECC5, 0);
    for (unsigned int i = 0; i < a->m_size; i++) {
        void* s = func_001E9378(a, i);
        int v = 0;
        if (func_001E8398(s, crc, &v, 0)) {
            func_0022A3F0(v, b, c, 0, 0);
        }
    }
    func_001ED1A0();
}
