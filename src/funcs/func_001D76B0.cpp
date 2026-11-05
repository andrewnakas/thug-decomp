struct Obj_001D76B0 {
    char pad[0xC];
    int mC;
    char pad2[0x30 - 0x10];
    int m30;
    int m34;
    int m38;
    int Move(int u, int dx, int dz, int dc, int dy, int w);
};
extern "C" void func_001D7E30(int a, int b, int c);

int Obj_001D76B0::Move(int u, int dx, int dz, int dc, int dy, int w)
{
    m30 = dx + m30;
    mC = mC + dc;
    m38 = dz + m38;
    m34 = m34 + dy;
    func_001D7E30(m34, dy, w);
    return 1;
}
