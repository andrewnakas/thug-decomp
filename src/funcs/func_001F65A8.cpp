struct Obj_001F65A8 {
    char pad[0x14];
    int m14;
    char pad2[0x40 - 0x18];
    int m40;
    void Align();
};
extern "C" int func_0031BCE0(int s);
extern "C" int func_0031BCC0(int s);

void Obj_001F65A8::Align()
{
    func_0031BCE0(m40);
    m14 = (m14 + 0x7FF) / 0x800 * 0x800;
    func_0031BCC0(m40);
}
