struct Pair_0012AFA8 {
    float a;
    float b;
};

struct C_0012AFA8 {
    char pad0[0x1B0];
    float m1B0;
    float m1B4;
    char pad1B8[0x1BC - 0x1B8];
    float m1BC;
    float m1C0;
    float m1C4;
    int m1C8;
    int m1CC;
    void Init(void* params);
};

extern "C" void func_003315B8(void* p, int c, int n);
extern "C" int func_00125A10(C_0012AFA8* self, void* params, unsigned int id, float* a, float* b);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" bool func_001E8708(void* params, unsigned int id);
extern "C" void func_00124328(C_0012AFA8* self, void* params);

void C_0012AFA8::Init(void* params)
{
    Pair_0012AFA8 p;
    func_003315B8(&p, 0, 8);
    if (func_00125A10(this, params, 0x67E093E4, &p.a, &p.b)) {
        m1B0 = p.a;
        m1B4 = p.b;
    }
    int a = 0;
    if (func_001E7DE8(params, 0xF24ADEDB, &a, 0))
        m1BC = a;
    func_001E7EB0(params, 0x6D853B88, &m1C0, 0);
    int b = 0;
    if (func_001E7DE8(params, 0x4B4E14AB, &b, 0))
        m1C4 = b;
    if (func_001E8708(params, 0x4BD08BFE))
        m1C8 = 1;
    else if (func_001E8708(params, 0xC22541CC))
        m1C8 = 0;
    if (func_001E8708(params, 0x43A7692D))
        m1CC = 1;
    else if (func_001E8708(params, 0x5DEA5C64))
        m1CC = 0;
    func_00124328(this, params);
}
