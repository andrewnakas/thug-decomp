struct Mgr_0022E3F0 {
    char pad[0x8C];
    int m_8C;
    void Report();
};

extern char D_00372BF8[];
extern "C" void func_00103F28(char* fmt, ...);
extern "C" void* func_0022E358(Mgr_0022E3F0* self);
extern "C" void func_0024FA70(void* a, int b);

void Mgr_0022E3F0::Report()
{
    func_00103F28(D_00372BF8);
    func_0024FA70(func_0022E358(this), m_8C);
}
