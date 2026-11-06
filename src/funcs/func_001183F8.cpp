/* sym: __12Prm_001183F8 = 0x001E6978 */
/* sym: _$_12Prm_001183F8 = 0x001E6AE8 */
extern "C" void* func_001190D0(int n);
extern "C" int func_001E5628(unsigned int name, int a);
extern char D_0035C590[];

struct Prm_001183F8 {
    int m0;
    int m4;
    Prm_001183F8();
    ~Prm_001183F8();
    static void* operator new(unsigned int size) { return func_001190D0(size); }
};

extern "C" void func_001E72B0(Prm_001183F8* p, int name, float v);
extern "C" int func_001F0370(char* script, Prm_001183F8* p, void* obj, int a);

class Evt_001183F8 {
public:
    char pad0[0x20];
    float m_value;
    int Run(void* obj);
};

int Evt_001183F8::Run(void* obj)
{
    func_001E5628(0x2F510F45, 0);
    Prm_001183F8* p = new Prm_001183F8;
    func_001E72B0(p, 0, m_value);
    func_001F0370(D_0035C590, p, obj, 0);
    delete p;
    return 1;
}
