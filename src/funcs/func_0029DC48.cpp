struct Vec_0029DC48 {
    float x, y, z, w;
};

extern "C" bool func_001E7EB0(void* s, unsigned int name, float* out, int a);
extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int a);
extern "C" bool func_001E7FA8(void* s, unsigned int name, Vec_0029DC48* v, int a);
extern "C" void func_003233B8(Vec_0029DC48* a, Vec_0029DC48* b);

struct Obj_0029DC48 {
    char pad[0x20];
    float m20;
    float m24;
    unsigned int m28;
    unsigned int m2C;
    Vec_0029DC48 m30;
    void Init(void* p);
};

void Obj_0029DC48::Init(void* p)
{
    func_001E7EB0(p, 0xC48391A5, &m20, 1);
    func_001E7EB0(p, 0x13B9DA7B, &m24, 1);
    func_001E8398(p, 0x81C39E06, &m2C, 1);
    func_001E8398(p, 0x6647ADC3, &m28, 1);
    Vec_0029DC48* v = &m30;
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = 1.0f;
    v->w = 1.0f;
    func_001E7FA8(p, 0x0C4C809E, v, 1);
    func_003233B8(v, v);
}
