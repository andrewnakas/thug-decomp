extern void* D_0038FC78;

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int assert_);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" void* func_0022E3C8(void* self, int index);
extern "C" void* func_0011FE68(void* self, unsigned int name);
extern "C" void func_001E7200(void* self, unsigned int name, int value);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E78A8(void* self, unsigned int name, void* value);

bool func_00221AD0(void* params)
{
    int index = 0;
    func_001E7DE8(params, 0x67E6859A, &index, 0);
    char* profile = (char*)func_0022E3C8(D_0038FC78, index);
    unsigned int part;
    func_001E8398(params, 0xB6F08F39, &part, 1);
    void* desc = func_0011FE68(profile + 4, part);
    if (!desc) {
        desc = func_001E6978(func_001190D0(8));
        func_001E78A8(profile + 0x4C, part, desc);
    }
    float h;
    float s;
    float v;
    int use;
    if (func_001E7EB0(params, 0x7323E97C, &h, 0)) {
        func_001E7200(desc, 0x7323E97C, (int)h);
    }
    if (func_001E7EB0(params, 0x0424D9EA, &s, 0)) {
        func_001E7200(desc, 0x0424D9EA, (int)s);
    }
    if (func_001E7EB0(params, 0x9D2D8850, &v, 0)) {
        func_001E7200(desc, 0x9D2D8850, (int)v);
    }
    if (func_001E7DE8(params, 0x5A96985D, &use, 0)) {
        func_001E7200(desc, 0x5A96985D, use);
    }
    return true;
}
