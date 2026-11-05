struct Mgr_002400D0 {
    char pad[0x5C];
    void* m_5C;
    void Set(int value);
};

extern void* D_0038FC78;
extern "C" void* func_0022E358(void* self);
extern "C" unsigned int func_0024F938(void* a);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

void Mgr_002400D0::Set(int value)
{
    func_001E7200(m_5C, func_0024F938(func_0022E358(D_0038FC78)), value);
}
