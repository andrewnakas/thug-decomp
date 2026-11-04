extern "C" unsigned int func_0010FC30();
extern "C" void func_001048F0(int p);
extern "C" void func_001F0370(void* a, int b, int c, int d);
extern char D_00378218[];

struct Inner {
    char pad0[0x9C];
    int m9C;
    char padA0[0x184 - 0xA0];
    unsigned int m184;
};

struct Obj_002A1838 {
    char pad0[0x20];
    struct Inner* m20;
    char pad24[0x38 - 0x24];
    int m38;
    int m3C;
    char pad40[0x168 - 0x40];
    int m_flags;
    void CheckTimeout();
};

void Obj_002A1838::CheckTimeout() {
    Inner* p = m20;
    if (func_0010FC30() - p->m184 > 60000) {
        func_001048F0(p->m9C);
        func_001F0370(D_00378218, 0, 0, 0);
    }
}
