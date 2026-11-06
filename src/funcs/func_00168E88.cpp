extern unsigned int* D_00394274;
extern "C" void func_001645F8(int flag, int b, int c);
extern "C" void func_001646D0(unsigned int eop);

static inline void Add_00168E88(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

static inline void Mark_00168E88(unsigned short v)
{
    Add_00168E88(v | 0x4000000);
}

void func_00168E88(unsigned int* src, int n, int flag, bool last)
{
    if (src) {
        func_001645F8(flag, 0, 0);
        for (int i = 0; i < n; i++) {
            Add_00168E88(*src++);
            Add_00168E88(*src++);
            Add_00168E88(*src++);
        }
        func_001646D0(0);
    }
    Mark_00168E88(last ? 2 : 1);
}
