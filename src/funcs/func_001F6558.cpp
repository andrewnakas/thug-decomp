struct Obj_001F6558 {
    char pad[0x10];
    int m10;
    int m14;
    char pad2[0x40 - 0x18];
    int m40;
    int Tell();
};
extern "C" void func_0031BCE0(int s);
extern "C" void func_0031BCC0(int s);

int Obj_001F6558::Tell()
{
    func_0031BCE0(m40);
    int r = m10 * 2048 + m14;
    func_0031BCC0(m40);
    return r;
}
