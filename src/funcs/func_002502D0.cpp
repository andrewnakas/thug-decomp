extern char D_003749C0[];
extern "C" void func_00103F28(char* fmt, int value);

struct Obj_002502D0 {
    int m_0;
    int m_4;
    int m_8;
    bool Print();
};

bool Obj_002502D0::Print()
{
    func_00103F28(D_003749C0, m_8);
    return true;
}
