extern void* D_0038FC78;

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int assert_);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" void* func_0022E3C8(void* self, int index);
extern "C" void* func_0011FE68(void* self, unsigned int name);
extern "C" void func_001E7200(void* self, unsigned int name, int value);
extern "C" void func_001E72B0(void* self, unsigned int name, float value);

bool func_00221C58(void* params)
{
    int index = 0;
    func_001E7DE8(params, 0x67E6859A, &index, 0);
    char* profile = (char*)func_0022E3C8(D_0038FC78, index) + 4;
    unsigned int part;
    func_001E8398(params, 0xB6F08F39, &part, 1);
    void* desc = func_0011FE68(profile, part);
    if (desc) {
        float a;
        float b;
        float c;
        float d;
        int use;
        func_001E7EB0(params, 0xCF6AA087, &a, 1);
        func_001E7EB0(params, 0x5663F13D, &b, 1);
        func_001E7EB0(params, 0x266932C8, &c, 1);
        func_001E7EB0(params, 0x1256B6C6, &d, 1);
        func_001E7DE8(params, 0x8602F6EE, &use, 1);
        func_001E72B0(desc, 0xCF6AA087, a);
        func_001E72B0(desc, 0x5663F13D, b);
        func_001E72B0(desc, 0x266932C8, c);
        func_001E72B0(desc, 0x1256B6C6, d);
        func_001E7200(desc, 0x8602F6EE, use);
    }
    return true;
}
