struct Inner_0011B2E0 {
    char pad[0x1C];
    float m_value;
};

struct Obj_0011B2E0;
extern "C" float func_0011B148(Obj_0011B2E0* self);
extern "C" void func_00144CB0(void* p, int a);

struct Obj_0011B2E0 {
    int m0;
    Inner_0011B2E0* m_inner;
    char pad8[0x30 - 8];
    void* m30;
    void Update();
};

void Obj_0011B2E0::Update()
{
    float old = m_inner->m_value;
    m_inner->m_value = func_0011B148(this);
    if (m_inner->m_value < old) {
        func_00144CB0(m30, 0);
    }
}
