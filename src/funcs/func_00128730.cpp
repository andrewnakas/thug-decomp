struct Obj_00128730;
extern char D_00389828[];
extern char D_0035CDD8[];
extern "C" void func_00124328(Obj_00128730* self, void* params);
extern "C" int func_001E84E8(void* params, const char* name, int* out, int required);
extern "C" int func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" void func_00128818(Obj_00128730* self, int tex);
extern "C" void func_001288A8(Obj_00128730* self, int a, float f);

struct Obj_00128730 {
    int m0;
    void Init(void* params);
};

void Obj_00128730::Init(void* params)
{
    int tex;
    float f;
    func_00124328(this, params);
    if (func_001E84E8(params, D_00389828, &tex, 0)) {
        func_00128818(this, tex);
    }
    if (func_001E7F50(params, D_0035CDD8, &f, 0)) {
        func_001288A8(this, 1, f);
    }
}
