extern void* D_0038C0F8;
extern "C" void* func_0010BDE0(int size);
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct F_0017DFE8 {
    unsigned long lo : 32;
    unsigned long flip : 1;
    unsigned long b1 : 1;
    unsigned long b2 : 1;
    unsigned long linked : 1;
    unsigned long rest : 28;
};

struct C_0017DFE8 {
    union {
        struct {
            int m0;
            int m_flags;
        } w;
        F_0017DFE8 f;
    };
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
    C_0017DFE8* InitCopy(C_0017DFE8* src);
    void Parse(int a);
};

C_0017DFE8* C_0017DFE8::InitCopy(C_0017DFE8* src)
{
    w.m0 = src->w.m0;
    w.m_flags = src->w.m_flags;
    m50 = 0;
    m3C = 0;
    m38 = 0;
    m14 = 0;
    m10 = 0;
    m1C = 0;
    m18 = 0;
    m_size = src->m_size;
    if (m_size && src->m_file) {
        m_file = func_0010BDE0(m_size);
        func_00331404(m_file, src->m_file, m_size);
        Parse(1);
    }
    if (f.linked && !f.flip) {
        m_next = D_0038C0F8;
        D_0038C0F8 = this;
    }
    return this;
}
