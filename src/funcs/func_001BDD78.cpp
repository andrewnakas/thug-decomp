struct Vec_001BDD78 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7FA8(void* params, unsigned int name, Vec_001BDD78* out, int req);
extern "C" void func_003233B8(Vec_001BDD78* d, Vec_001BDD78* s);

struct C_001BDD78 {
    char pad[0x20];
    float m20;
    float m24;
    int m28;
    unsigned int m2C;
    char pad30[0x10];
    Vec_001BDD78 m40;
    void Init(void* params);
};

void C_001BDD78::Init(void* params)
{
    Vec_001BDD78* dir = &m40;
    func_001E7EB0(params, 0xC48391A5, &m20, 1);
    func_001E7EB0(params, 0x13B9DA7B, &m24, 1);
    func_001E8398(params, 0x6647ADC3, &m2C, 1);
    dir->Set(0.0f, 0.0f, 1.0f, 1.0f);
    func_001E7FA8(params, 0x0C4C809E, dir, 1);
    func_003233B8(dir, dir);
}
