extern "C" int func_0025D770(void* p);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_0025DAC0(void* p, int a, int b);

struct Obj_0025EBF0 {
    char pad[0x18];
    int m18;
    char pad1C[0x20];
    void* m3C;
    char pad40[4];
    unsigned int m44;
    int m48;
    char pad4C[4];
    int m50;
    void Fn();
};

void Obj_0025EBF0::Fn()
{
    if (m3C && func_0025D770(m3C)) {
        if (!m48) {
            if (m44) {
                func_001F0210(m44, 0, 0, 0, 0);
                m48 = 1;
            }
        }
        func_0025DAC0(m3C, m18, m50);
    }
}
