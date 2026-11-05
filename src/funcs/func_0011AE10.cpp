struct Inner_0011AE10 {
    char pad[0x1C];
    float m_value;
};

extern "C" float func_001194A8(Inner_0011AE10* p);
extern "C" void func_0011A870(Inner_0011AE10* p, float from, float to);
extern "C" void func_00144CB0(void* p, int a);

struct Obj_0011AE10 {
    int m0;
    Inner_0011AE10* m_inner;
    char pad8[0x18 - 8];
    void* m18;
    void Update();
};

void Obj_0011AE10::Update()
{
    float old = m_inner->m_value;
    m_inner->m_value = func_001194A8(m_inner);
    func_0011A870(m_inner, old, m_inner->m_value);
    if (m_inner->m_value < old) {
        func_00144CB0(m18, 0);
    }
}
