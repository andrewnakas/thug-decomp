extern "C" int func_00185578(void* p, unsigned int key);

struct Obj_001CDFB0 {
    char m_pad[0xB0];
    void* m_B0;
    int m_B4;
    int m_B8;
    void Set(void* p);
};

void Obj_001CDFB0::Set(void* p)
{
    if (p) {
        m_B0 = p;
        m_B4 = func_00185578(p, 0x726E85AA);
        m_B8 = func_00185578(m_B0, 0xD9151D4D);
    } else {
        m_B0 = 0;
        m_B4 = 0;
        m_B8 = 0;
    }
}
