extern "C" void* func_001E5548(unsigned int id, int flag);
extern "C" int func_001E8180(void* params, unsigned int id, void* out, int required);
extern "C" int func_001E8618(void* params, unsigned int id);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int required);
extern "C" int func_001E7EB0(void* params, unsigned int id, void* out, int required);
extern "C" void func_001E6AE8(void* p, int mode);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6A50(void* p, void* src);

struct C_001920A8 {
    char pad[0x98];
    void* m98;
    void* m9C;
    int mA0;
    int mA4;
    int mA8;
    int mAC;
    void Load(unsigned int name);
};

void C_001920A8::Load(unsigned int name)
{
    void* cfg = func_001E5548(0xB9738EBA, 1);
    void* params = 0;
    void* sub;
    int a;
    int b;
    func_001E8180(cfg, name, &params, 0);
    if (func_001E8618(params, 0xBF8E0ACE)) {
        func_001E8180(params, 0xBF8E0ACE, &sub, 1);
        if (m98) func_001E6AE8(m98, 3);
        m98 = func_001E6978(func_001190D0(8));
        func_001E6A50(m98, sub);
    }
    if (func_001E8618(params, 0x1FB2F60C)) {
        func_001E8180(params, 0x1FB2F60C, &sub, 1);
        if (m9C) func_001E6AE8(m9C, 3);
        m9C = func_001E6978(func_001190D0(8));
        func_001E6A50(m9C, sub);
        if (func_001E8618(params, 0x3818EE47)) {
            func_001E7DE8(params, 0x3818EE47, &a, 0);
            mA0 = a;
        }
        if (func_001E8618(params, 0xAD67A34D)) {
            func_001E7DE8(params, 0xAD67A34D, &b, 0);
            mA4 = b;
        }
        func_001E7EB0(params, 0x4511CA8D, &mA8, 0);
        func_001E7EB0(params, 0x8FC6519F, &mAC, 0);
    }
}
