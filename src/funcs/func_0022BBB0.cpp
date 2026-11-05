struct Child_0022BBB0 {
    int m0;
    int m4;
    virtual ~Child_0022BBB0() = 0;
};

struct Sub_0022BBB0 {
    int m0;
    char m4[1];
};

struct Obj_0022BBB0 {
    char pad[0x18];
    void* m_18;
    void* m_1C;
    void* m_20;
    void* m_24;
    char pad28[0x5C - 0x28];
    Sub_0022BBB0* m_5C;
    Child_0022BBB0* m_60;
    void Free();
};

extern "C" void func_001048F0(void* p);
extern "C" void func_001FC128(void* p);

void Obj_0022BBB0::Free()
{
    if (m_60) {
        delete m_60;
        m_60 = 0;
    }
    func_001048F0(m_18);
    func_001048F0(m_20);
    func_001048F0(m_24);
    func_001048F0(m_1C);
    func_001FC128(m_5C->m4);
}
