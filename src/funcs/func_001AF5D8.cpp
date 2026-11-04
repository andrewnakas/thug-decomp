extern "C" int func_0026F8D8(int a, int b, int c, int d);

extern "C" void func_001ABEC8(void* self, int id, int on);

struct S_001AF5D8 {
    int m_pad[8];
    int m_flags;
};

struct C_001AF5D8 {
    int m_pad[9];
    S_001AF5D8* m24;
    void Refresh();
};

void C_001AF5D8::Refresh()
{
    int f = m24->m_flags;
    int mode = func_0026F8D8((f >> 6) & 1, (f >> 7) & 1, (f >> 5) & 1, (f >> 4) & 1);
    func_001ABEC8(this, 1, mode == 1);
    func_001ABEC8(this, 2, mode == 2);
    func_001ABEC8(this, 3, mode == 3);
    func_001ABEC8(this, 4, mode == 4);
    func_001ABEC8(this, 5, mode == 5);
    func_001ABEC8(this, 6, mode == 6);
    func_001ABEC8(this, 7, mode == 7);
    func_001ABEC8(this, 8, mode == 8);
    func_001ABEC8(this, 9, (f >> 9) & 1);
    func_001ABEC8(this, 10, (f >> 11) & 1);
    func_001ABEC8(this, 12, (f >> 8) & 1);
    func_001ABEC8(this, 11, (f >> 10) & 1);
    func_001ABEC8(this, 13, (f >> 12) & 1);
    func_001ABEC8(this, 14, (f >> 14) & 1);
    func_001ABEC8(this, 15, (f >> 16) & 1);
    func_001ABEC8(this, 16, (f >> 13) & 1);
    func_001ABEC8(this, 17, (f >> 15) & 1);
    func_001ABEC8(this, 18, (f >> 17) & 1);
    func_001ABEC8(this, 19, (f >> 22) & 1);
    func_001ABEC8(this, 20, (f >> 23) & 1);
    func_001ABEC8(this, 21, (f >> 24) & 1);
}
