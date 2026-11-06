struct Entry_001728E8 {
    char pad0[0xC];
    void* mC;
    char pad10[0x50 - 0x10];
};

struct Model_001728E8 {
    char pad0[0x30];
    int m30;
    int m34;
    Entry_001728E8* m38;
};

struct Obj_001728E8 {
    char pad0[0x70];
    Model_001728E8* m70;
    void Fn();
};

extern "C" void func_001622E8(void* pkt);
extern "C" void func_001627A8(void* pkt);

void Obj_001728E8::Fn()
{
    Entry_001728E8* e = m70->m38;
    int n = m70->m30;
    for (int i = 0; i < n; i++, e++) {
        func_001622E8(e->mC);
        func_001627A8(e->mC);
    }
}
