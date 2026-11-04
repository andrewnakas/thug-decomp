extern void* D_0038FC78;

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int assert_);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" void* func_0022E3C8(void* self, int index);
extern "C" void* func_0011FE68(void* self, unsigned int name);
extern "C" void func_001E7200(void* self, unsigned int name, int value);

bool func_00221988(void* params)
{
    int index = 0;
    func_001E7DE8(params, 0x67E6859A, &index, 0);
    char* profile = (char*)func_0022E3C8(D_0038FC78, index) + 4;
    unsigned int part;
    func_001E8398(params, 0xB6F08F39, &part, 1);
    void* desc = func_0011FE68(profile, part);
    if (desc) {
        float h;
        float s;
        float v;
        int use;
        func_001E7EB0(params, 0x6E94F918, &h, 1);
        func_001E7EB0(params, 0xE4F130F4, &s, 1);
        func_001E7EB0(params, 0x949BC47B, &v, 1);
        func_001E7DE8(params, 0x97DBDDE6, &use, 1);
        func_001E7200(desc, 0x6E94F918, (int)h);
        func_001E7200(desc, 0xE4F130F4, (int)s);
        func_001E7200(desc, 0x949BC47B, (int)v);
        func_001E7200(desc, 0x97DBDDE6, use);
    }
    return true;
}
