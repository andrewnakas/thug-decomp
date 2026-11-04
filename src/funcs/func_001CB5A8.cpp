struct Quat_001CB5A8 {
    float x, y, z, w;
    void Set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

struct Obj_001CB5A8 {
    char m_pad0[0xC4];
    float m_C4;
    char m_pad1[0x970 - 0xC8];
    Quat_001CB5A8 m_970;
    char m_pad2[0xA34 - 0x980];
    void* m_A34;
    int m_A38;
    void* m_A3C;
    char m_pad3[0xA70 - 0xA40];
    char m_A70[0xB50 - 0xA70];
    int m_B50;
    char m_pad4[0xC44 - 0xB54];
    float m_C44;
    void Reset();
};

extern "C" void func_001BF130(Obj_001CB5A8* self, int a);
extern "C" void func_001BB080(void* p, int id, void* data);
extern "C" void func_001CE768(void* p, void* data);

void Obj_001CB5A8::Reset()
{
    func_001BF130(this, 0);
    if (m_B50) {
        func_001BB080(m_A34, 5, m_A70);
        func_001CE768(m_A3C, m_A70);
    }
    m_970.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m_C4 = m_C44;
}
