extern "C" bool func_001DC418();
extern "C" void func_001DC5A8(void* obj, float v);

struct Params_001DD1E8 {
    float m0;
    float m4;
    float m8;
    float mC;
};

struct Obj_001DD1E8 {
    void Apply(void* obj, float* out, Params_001DD1E8* p);
};

void Obj_001DD1E8::Apply(void* obj, float* out, Params_001DD1E8* p)
{
    if (func_001DC418())
        return;
    func_001DC5A8(obj, 50.0f);
    if (p->mC != 100.0f)
        func_001DC5A8(obj, p->mC);
    if (p->m8 != 100.0f)
        *out = *out * p->m8 * 0.01f;
}
