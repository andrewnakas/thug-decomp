extern char D_00379F78[];
extern char D_00379F88[];
extern char D_00379F98[];

struct Stats_002B74F0 {
    int v[9];
};

struct Prof_002B74F0 {
    char pad[0x20];
    int m20;
    char pad24[8];
    int m2C;
    char pad30[4];
    void* m34;
};

struct Heap_002B74F0 {
    char pad[0xDC];
    Prof_002B74F0* mDC;
};

extern Heap_002B74F0* D_00388A70;
extern "C" int func_0010C258(void* p);
extern "C" int func_0010CAC0(Prof_002B74F0* p);
extern "C" void* func_002C0368();
struct Obj_002B74F0;
extern "C" int func_002B73B8(Obj_002B74F0* o, char* name);
extern "C" int func_002BD248(void* p);

struct Obj_002B74F0 {
    char pad0[0xC];
    int mC;
    char pad10[0x10];
    void* m20;
    Prof_002B74F0* m24;
    int m28;
    char pad2C[0x9C - 0x2C];
    int m9C;
    int mA0;
    char padA4[0x534 - 0xA4];
    int m534;
    int m538;
    int m53C;
    int m540;
    int m544;
    int m548;
    int m54C;
    int m550;
    int m554;
    Stats_002B74F0 Compute();
};

Stats_002B74F0 Obj_002B74F0::Compute()
{
    Prof_002B74F0* p = D_00388A70->mDC;
    void* q = p->m34;
    if (m53C != p->m20)
        m544 = m53C;
    int base = func_002B73B8(this, D_00379F78) + (m28 - 1) * 0xB5658;
    func_0010C258(q);
    m53C = p->m20;
    m540 = p->m2C + func_0010C258(q) - base;
    int b2 = func_002B73B8(this, D_00379F98);
    m534 = m24->m20;
    m538 = m24->m2C + func_0010C258(m20) - b2;
    if (func_0010CAC0(p) < m540 && func_0010CAC0(p) < base && !(m540 < base)) {
        m548 = 1;
        int v = func_0010CAC0(p);
        int d = m540 - v;
        m540 -= d;
        m53C += d;
    } else {
        m548 = 0;
    }
    m554 = mC;
    m54C = m9C;
    m550 = mA0;
    if (func_002BD248(func_002C0368()) > 0)
        m540 -= func_002B73B8(this, D_00379F88);
    return *(Stats_002B74F0*)&m534;
}
