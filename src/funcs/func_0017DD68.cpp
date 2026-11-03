extern void* D_0038C0F8;
extern char D_003610B0[];
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" void* func_0010E1E8(const char* name, int* size, int a, int b);

struct C_0017DD68 {
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
    C_0017DD68* InitFromFile(const char* name, int linked, int a8, int flip);
    void Parse(int a);
    void FlipV();
};

C_0017DD68* C_0017DD68::InitFromFile(const char* name, int linked, int a8, int flip)
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
    char path[128];
    if (linked) {
        func_00331A9C(path, name);
    } else {
        func_00331A9C(path, name);
    }
    func_00331678(path, D_003610B0);
    m14 = 0;
    m10 = 0;
    m1C = 0;
    m18 = 0;
    m_file = func_0010E1E8(path, &m_size, 0, 0);
    Parse(0);
    if (linked && !flip) {
        m_next = D_0038C0F8;
        D_0038C0F8 = this;
    }
    if (flip) FlipV();
    return this;
}
