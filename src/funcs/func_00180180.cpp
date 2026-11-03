struct Model_00180180 {
    int m0[4];
    int m10;
    int m_count;
    int m18;
    unsigned int* m_data;
    unsigned char* m_buffer;
    void* m_meshes;
    int m28[2];
    int m30;
    int m34;
    int m38;
    int m3C;
    Model_00180180* m_next;
};

extern Model_00180180* D_00394310;
extern unsigned int* D_00394320;
extern unsigned int D_00394324;
extern unsigned char* D_00394274;
extern int D_00394304;
extern void* D_003E3418[];
extern "C" void func_00165058();
extern "C" void* func_0010BDE0(int size);
extern "C" void* func_0010BE88(int size, void* p);
extern "C" void* func_003315B8(void* p, int c, unsigned int n);
extern "C" void func_001804E8(int a, Model_00180180* m, void* d, int b, int c, int e, int f);


extern "C" int func_00180180(Model_00180180* m, unsigned int* data, int a, int b, int flags, int c)
{
    int n = 0;
    func_00165058();
    m->m18 = 0;
    m->m_next = D_00394310;
    m->m30 = 0;
    m->m38 = 0;
    m->m10 = 0;
    m->m3C = 0;
    D_00394310 = m;
    if (flags) {
        m->m10 = 2;
    }
    m->m_data = data;
    D_00394320 = data;
    D_00394324 = *D_00394320;
    D_00394320++;
    m->m_count = *D_00394320;
    D_00394320++;
    if (D_00394324 >= 3) {
        n = *D_00394320;
        D_00394320++;
        if (n > 0) {
            m->m_meshes = func_0010BDE0(n * 0x48);
        } else {
            m->m_meshes = 0;
        }
    } else {
        m->m_meshes = func_0010BDE0(0x23280);
    }
    if (n != 0 && m->m_meshes == 0) {
        return 0;
    }
    int i;
    for (i = 0; i < m->m_count; i++) {
        D_003E3418[i] = func_0010BDE0(0x58);
        func_003315B8(D_003E3418[i], 0, 0x58);
    }
    int size = (n << 9) + (m->m_count << 7) + 0x200;
    m->m_buffer = (unsigned char*)func_0010BDE0(size);
    D_00394274 = m->m_buffer;
    D_00394304 = 0x2BC0;
    for (int j = 0; j < m->m_count; j++) {
        func_001804E8(0, m, D_003E3418[j], a, b, flags, c);
        D_003E3418[j] = 0;
    }
    int used = D_00394274 - m->m_buffer;
    if (used >= size) {
        return 0;
    }
    m->m_buffer = (unsigned char*)func_0010BE88(used, m->m_buffer);
    return 1;
}
