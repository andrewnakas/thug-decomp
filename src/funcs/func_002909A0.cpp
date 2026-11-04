struct Sub_002909A0 {
    char pad[0x80];
};

extern "C" void func_00260590(Sub_002909A0* s, void* p);

struct Obj_002909A0 {
    char pad0[0xC];
    void* mC;
    char pad10[0x30 - 0x10];
    Sub_002909A0 m_sub[4];
    void Init();
};

void Obj_002909A0::Init()
{
    func_00260590(&m_sub[0], mC);
    func_00260590(&m_sub[1], mC);
    func_00260590(&m_sub[2], mC);
    func_00260590(&m_sub[3], mC);
}
