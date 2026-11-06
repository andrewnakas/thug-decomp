extern "C" int func_001E5628(unsigned int name, int a);
extern "C" int func_001F0210(unsigned int script, void* params, void* obj, int a, int b);

class Evt_001184D8 {
public:
    char pad0[0x20];
    unsigned int m_script;
    int Run(void* obj);
};

int Evt_001184D8::Run(void* obj)
{
    func_001E5628(0x2F510F45, 0);
    func_001F0210(m_script, 0, obj, 0, 0);
    return 1;
}
