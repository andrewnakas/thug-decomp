extern "C" void* func_00121960(int size);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001EE428(void* mem);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6AC8(void* p, void* a);
extern "C" void func_001EE8C8(void* p, void* a, void* b, void* owner);

class C_00140400 {
public:
    char m_pad0[0x1D0];
    void* m_1D0;
    void* m_1D4;
    void* m_1D8;
    void Play(void* a, void* b);
};

void C_00140400::Play(void* a, void* b)
{
    if (a) {
        if (!m_1D4) {
            m_1D4 = func_001EE428(func_00121960(0xF4));
        }
        if (!m_1D8) {
            m_1D8 = func_001E6978(func_001190D0(8));
        }
        func_001E6AC8(m_1D8, b);
        func_001EE8C8(m_1D4, a, m_1D8, this);
    }
}
