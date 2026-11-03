extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct C_0017EA80 {
    char pad[0x10];
    char* m_data;
    char pad14[0x40 - 0x14];
    unsigned short m_width;
    unsigned short m_height;
    int GetBpp();
    void FlipV();
};

void C_0017EA80::FlipV()
{
    int bottom = m_height - 1;
    int row = m_width * GetBpp() / 8;
    char* tmp = (char*)func_0010A638(D_00388A70, row, 1, 0);
    for (int i = 0; i < bottom; i++, bottom--) {
        func_00331404(tmp, m_data + i * row, row);
        func_00331404(m_data + i * row, m_data + bottom * row, row);
        func_00331404(m_data + bottom * row, tmp, row);
    }
    func_0010A8D8(D_00388A70, tmp);
}
