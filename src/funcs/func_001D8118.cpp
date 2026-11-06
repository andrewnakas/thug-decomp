extern unsigned short D_0034EDE8[];
extern unsigned short D_004657E8[];
extern int D_0039432C;
extern "C" void func_001D7FE0(void* self, int a, int b);

struct Obj_001D8118 {
    char m_pad0[0x8];
    unsigned short m8;
    char m_padA[0x34 - 0xA];
    int m34;
    unsigned short* Get(int b, int* count);
};

unsigned short* Obj_001D8118::Get(int b, int* count)
{
    unsigned short* table;
    if (m34) {
        D_0039432C = 0;
        func_001D7FE0(this, m34, b);
        *count = D_0039432C;
        table = D_004657E8;
    } else {
        *count = m8;
        table = D_0034EDE8;
    }
    return table;
}
