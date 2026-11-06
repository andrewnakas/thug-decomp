extern "C" void func_00172688(void* p);

class Obj_0014E1A0 {
public:
    char pad[0x18];
    void* m_18;
    int m_1C;
    int m_20;
    bool Run();
};

bool Obj_0014E1A0::Run()
{
    if (!m_20) func_00172688(m_18);
    return true;
}
