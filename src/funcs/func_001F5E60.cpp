extern "C" int func_0031BCE0(int sema);
extern "C" void func_0031BCC0(int sema);

struct Obj_001F5E60 {
    char m_pad0[0x14];
    int m14;
    char m_pad18[0x40 - 0x18];
    int m40;
    int m44;
    long m48;
    void Add(int n);
};

void Obj_001F5E60::Add(int n)
{
    func_0031BCE0(m40);
    m14 += n;
    m48 += n;
    func_0031BCC0(m40);
}
