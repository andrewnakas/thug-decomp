extern "C" void func_001EE4D8(void* p, int flags);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void* func_001324B0();
extern "C" void func_001410B0(void* mgr, void* entry);

class B_0013F8B0 {
public:
    int m_0;
    int m_4;
    virtual void V0();
    virtual ~B_0013F8B0();
};

class C_0013F8B0 : public B_0013F8B0 {
public:
    virtual void V1();
    virtual ~C_0013F8B0();
    char m_padC[0x1B8];
    int m_1C4[3];
    void* m_1D0;
    void* m_1D4;
    void* m_1D8;
};

C_0013F8B0::~C_0013F8B0()
{
    if (m_1D0) {
        func_001EE4D8(m_1D0, 3);
    }
    if (m_1D4) {
        func_001EE4D8(m_1D4, 3);
    }
    if (m_1D8) {
        func_001E6AE8(m_1D8, 3);
    }
    func_001410B0(func_001324B0(), m_1C4);
}
