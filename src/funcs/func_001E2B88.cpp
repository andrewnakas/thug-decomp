extern "C" void func_001E28F8(int a, int b, int c, int d);
extern int D_0038E280;

struct Obj_001E2B88 {
    int m_0;
    char pad4[0xC];
    int m_10;
    char pad14[8];
    int m_1C;
    int m_20;
};

void Apply_001E2B88(Obj_001E2B88* o)
{
    int n = o->m_0;
    D_0038E280 = (D_0038E280 & ~(0x10000 << n)) | (0x100 << n);
    if (n == 0) {
        func_001E28F8(0x20, o->m_10 / 2, 0, 0);
    } else {
        func_001E28F8((n - 1) | 0x40, o->m_10, o->m_20, o->m_1C);
    }
}
