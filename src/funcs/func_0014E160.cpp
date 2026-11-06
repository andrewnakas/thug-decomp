struct Sub_0014E160 {
    char pad[0xC0];
    int m_C0;
};

extern "C" void func_0014CFC0(Sub_0014E160* p);

class Obj_0014E160 {
public:
    char pad[0x1C];
    Sub_0014E160* m_1C;
    int m_20;
    bool Run();
};

bool Obj_0014E160::Run()
{
    if (!m_20) {
        Sub_0014E160* s = m_1C;
        if (!s->m_C0) func_0014CFC0(s);
    }
    return true;
}
