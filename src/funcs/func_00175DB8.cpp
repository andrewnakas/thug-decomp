extern unsigned int* D_00394274;
extern unsigned int D_00394280;
extern unsigned int D_00394294;
extern char D_310[];
extern "C" void func_00175C70(int a);

static inline void Add_00175DB8(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

void func_00175DB8()
{
    func_00175C70(1);
    Add_00175DB8((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
    Add_00175DB8(0x11000000);
}
