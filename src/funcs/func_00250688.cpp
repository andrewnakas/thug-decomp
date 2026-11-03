extern char D_003749E8[];
extern "C" void func_00103F28(char* fmt, int value);

struct Obj_00250688 {
    int m_0;
    int m_4;
    int m_8;
    bool Print();
};

bool Obj_00250688::Print()
{
    func_00103F28(D_003749E8, m_8);
    return true;
}
