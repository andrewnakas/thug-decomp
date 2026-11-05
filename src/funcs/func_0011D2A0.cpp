struct Inner_0011D2A0 {
    char pad[0x1C];
    float m_value;
};

struct Obj_0011D2A0;
extern "C" float func_001194A8(Inner_0011D2A0* p);
extern "C" void func_00144CB0(void* p, int a);

struct Obj_0011D2A0 {
    char pad[0x18];
    Inner_0011D2A0* m_inner;
    void* m30;
    void Update();
};

void Obj_0011D2A0::Update()
{
    float old = m_inner->m_value;
    m_inner->m_value = func_001194A8(m_inner);
    if (m_inner->m_value < old) {
        func_00144CB0(m30, 0);
    }
}
