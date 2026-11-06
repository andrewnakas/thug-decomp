class Obj_0014E048 {
public:
    int m_0;
    int m_4;
    char pad8[0x18];
    void* m_20;
    char pad24[0xC];
    char m_30[4];
    void Update();
};

extern "C" void func_00170730(void* a, void* b);

void Obj_0014E048::Update()
{
    if (m_4 != 2)
        func_00170730(m_20, m_30);
}
