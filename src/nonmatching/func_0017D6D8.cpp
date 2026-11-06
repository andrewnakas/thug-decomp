/* fuzzy: 83.3 */
struct Model_0017D6D8 {
    int m0[4];
    unsigned int m_flags;
    int m_version;
    int m18[6];
    int m_count;
    unsigned char* m_buffer;
    void* m_meshes;
    int m3C;
    int m40;
    int m44;
};

extern unsigned int D_00394314;
extern unsigned int D_00394318;
extern int D_0039431C;
extern unsigned char* D_00394274;
extern void* D_00388A70;
extern "C" void func_003312D8(int a, int b);
extern "C" unsigned char* func_00174818(unsigned char* p, Model_0017D6D8* m, int c);
extern "C" void* func_0010BDE0(int size);
extern "C" void func_00174EC8(unsigned char* p, Model_0017D6D8* m, int a, int b, int c);
extern "C" void func_0010A830(void* heap, int size, void* p, int a);

static inline unsigned char* Read(void* dst, unsigned char* p, int n)
{
    unsigned char* d = (unsigned char*)dst;
    for (; n > 0; n--) {
        *d++ = *p++;
    }
    return p;
}

extern "C" int func_0017D6D8(unsigned char* p, int size, Model_0017D6D8* m, int a, int flags, int c)
{
    int header;
    int version;
    int meshes;
    m->m44 = 0;
    func_003312D8(0, 0);
    int alloc = size / 10 + 2000;
    p = Read(&D_00394314, p, 4);
    p = Read(&D_00394318, p, 4);
    p = Read(&header, p, 4);
    p = func_00174818(p, m, c);
    p = Read(&version, p, 4);
    if (version != m->m_version) {
        return 0;
    }
    meshes = 0;
    if (D_00394318 >= 4) {
        p = Read(&meshes, p, 4);
        alloc = meshes * 0x50;
    }
    if (m->m_count != 0) {
        return 0;
    }
    m->m_meshes = func_0010BDE0(alloc);
    if (!m->m_meshes) {
        return 0;
    }
    int bufsize = size;
    if (size <= 0x493DF) {
        bufsize = size * 110 / 100;
    }
    m->m_buffer = (unsigned char*)func_0010BDE0(bufsize);
    if (!m->m_buffer) {
        return 0;
    }
    D_00394274 = m->m_buffer;
    D_0039431C = 0;
    func_00174EC8(p, m, a, flags, c);
    if (alloc < m->m_count * 0x50) {
        return 0;
    }
    func_0010A830(D_00388A70, D_00394274 - m->m_buffer, m->m_buffer, 0);
    if (D_00394318 < 4) {
        func_0010A830(D_00388A70, m->m_count * 0x50, m->m_meshes, 0);
    }
    m->m44 = 0;
    m->m3C = 0;
    if (flags) {
        m->m_flags |= 1;
    }
    return 1;
}
