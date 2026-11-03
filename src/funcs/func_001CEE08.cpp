extern "C" void func_001E7360(void* params, unsigned int key, int value);
extern "C" void func_001E77D0(void* params, unsigned int key, int value);
extern "C" void func_00184EB0(void* self, void* params);

struct Comp_001CEE08 {
    char pad[0x2C];
    int m2C;
    int m30;
    int m34;
    void GetDebugInfo(void* params);
};

void Comp_001CEE08::GetDebugInfo(void* params)
{
    func_001E7360(params, 0x2A19E830, m30);
    func_001E7360(params, 0xE798FE80, m34);
    func_001E77D0(params, 0x36FA68D2, m2C);
    func_00184EB0(this, params);
}
