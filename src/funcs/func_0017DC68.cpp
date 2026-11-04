extern void* D_0038C0F8;
extern "C" void* func_0010BDE0(int size);
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct C_0017DC68 {
    int m0;
    int m_flags;
    int m8;
    void* m_file;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m_size;
    char pad28[0x38 - 0x28];
    int m38;
    int m3C;
    unsigned short m_width;
    unsigned short m_height;
    int m44;
    int m48;
    void* m_next;
    int m50;
    C_0017DC68* InitFromMemory(void* src, int size, int linked, int a8, int flip);
    void Parse(int a);
    void FlipV();
};

C_0017DC68* C_0017DC68::InitFromMemory(void* src, int size, int linked, int a8, int flip)
{
    m_flags = 0;
    m50 = 0;
    m3C = 0;
    m38 = 0;
    if (flip) m_flags = 1;
    if (linked) {
        m_flags |= 8;
        if (a8 && !flip) m_flags |= 2;
    }
    m14 = 0;
    m10 = 0;
    m1C = 0;
    m18 = 0;
    m_file = func_0010BDE0(size);
    func_00331404(m_file, src, size);
    m_size = size;
    Parse(0);
    if (linked && !flip) {
        m_next = D_0038C0F8;
        D_0038C0F8 = this;
    }
    if (flip) FlipV();
    return this;
}
