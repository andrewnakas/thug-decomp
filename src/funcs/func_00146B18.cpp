class Obj_00146B18 {
public:
    char pad[0x30];
    void* m_30;
    char pad34[0xC];
    char m_40[4];
    void Update();
};

extern "C" void func_00170730(void* a, void* b);

void Obj_00146B18::Update()
{
    if (m_30)
        func_00170730(m_30, m_40);
}
