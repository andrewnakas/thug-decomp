extern char D_003897B8[];
extern "C" void* func_00130B80(void* o);
extern "C" void func_00135890(void* font, const char* text, float* w, float* h);

struct C_00127658 {
    int m0;
    int m4;
    int m8;
    unsigned int m_flags;
    char pad10[0x18C - 0x10];
    float m18C;
    char pad190[0x1A0 - 0x190];
    void* m1A0;
    char pad1A4[0x1B8 - 0x1A4];
    int m_maxLines;
    char pad1BC[0x1C4 - 0x1BC];
    float m_scale;
    void SetFont(void* f);
};

void C_00127658::SetFont(void* f)
{
    float w;
    float h;
    m1A0 = f;
    void* font = func_00130B80(f);
    func_00135890(font, D_003897B8, &w, &h);
    m_maxLines = (int)m18C / (int)(h * m_scale);
    m_flags |= 0x1000;
}
