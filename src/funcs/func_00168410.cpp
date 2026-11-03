extern "C" unsigned int func_001707A0(void* p);

struct Col_00168410 {
    float r, g, b, a;
    float& R() { return r; }
    float& G() { return g; }
    float& B() { return b; }
    float& A() { return a; }
};

struct C_00168410 {
    char pad[0xB0];
    Col_00168410 m_col;
    void SetColor(void* src);
};

void C_00168410::SetColor(void* src)
{
    unsigned int c = func_001707A0(src);
    m_col.R() = (float)(c & 0xFF) * (1.0f / 128.0f);
    m_col.G() = (float)((c >> 8) & 0xFF) * (1.0f / 128.0f);
    m_col.B() = (float)((c >> 16) & 0xFF) * (1.0f / 128.0f);
    m_col.A() = (float)(c >> 24) * (1.0f / 128.0f);
}
