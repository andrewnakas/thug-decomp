class Obj_0013D910;
extern "C" void func_0013D950(Obj_0013D910* self, bool b);

class Obj_0013D910 {
public:
    char pad0[0x1B0];
    unsigned long m_b0 : 2;
    unsigned long m_flag : 1;
    void SetFlag(bool on);
};

void Obj_0013D910::SetFlag(bool on)
{
    m_flag = on;
    func_0013D950(this, !on);
}
