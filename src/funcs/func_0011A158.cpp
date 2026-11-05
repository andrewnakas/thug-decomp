extern "C" void func_00119730(void* self);

struct Obj_0011A158 {
    char pad[0x38];
    int m_38;
    char pad2[0x18];
    int m_54;
    int m_58;
    void Reset();
};

void Obj_0011A158::Reset()
{
    func_00119730(this);
    m_38 = 0;
    m_54 = 0;
    m_58 = 0;
}
