extern "C" void func_00107CA0(void* mgr, int slot, int a);

struct Slot1BABD8 {
    void* p;
    int m4;
    int m8;
};

struct Comp1BABD8 {
    int m_pad[7];
    int m1C;
    Slot1BABD8 m20[2];
    void* m38;
    void Clear();
};

void Comp1BABD8::Clear()
{
    if (m1C) {
        int n = 2;
        while (n--) {
            func_00107CA0(m38, n, 0);
            m20[n].p = 0;
        }
    }
}
