extern "C" float func_001E5318(unsigned int name, int req);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);

struct Obj_001A4F60 {
    char pad[0x38];
    float m38;
    float m3C;
    float m40;
    float m44;
    void Method(void* params);
};

void Obj_001A4F60::Method(void* params)
{
    m38 = func_001E5318(0x877DB8DA, 1);
    func_001E7EB0(params, 0x877DB8DA, &m38, 0);
    m3C = func_001E5318(0xFB3464DF, 1);
    func_001E7EB0(params, 0xFB3464DF, &m3C, 0);
    m40 = func_001E5318(0xFD8BC8D6, 1);
    func_001E7EB0(params, 0xFD8BC8D6, &m40, 0);
    m44 = func_001E5318(0xB2C7447B, 1);
    func_001E7EB0(params, 0xB2C7447B, &m44, 0);
}
