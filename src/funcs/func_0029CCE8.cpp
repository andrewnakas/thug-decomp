extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int a);
extern "C" bool func_001E8708(void* s, unsigned int name);

struct Obj_0029CCE8 {
    char pad[0x74];
    float m74;
    float m78;
    char pad2[0x90 - 0x7C];
    float m90;
    int m94;
    int m98;
    void Init(void* p);
};

void Obj_0029CCE8::Init(void* p)
{
    m90 = 0.0f;
    func_001E7EB0(p, 0x9CDF40CD, &m90, 0);
    m74 = 100.0f;
    func_001E7EB0(p, 0x52EECB98, &m74, 0);
    m78 = 2000.0f;
    func_001E7EB0(p, 0x53E2512C, &m78, 0);
    m94 = func_001E8708(p, 0xA0D7FBAB);
    m98 = func_001E8708(p, 0xF5680DEF);
}
