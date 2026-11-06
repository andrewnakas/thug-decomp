extern char D_0035CDD8[];
extern "C" int func_001E7F50(void* params, const char* name, float* out, int req);

class Elem_001287B8;
extern "C" void func_00124868(Elem_001287B8* self, void* params);
extern "C" void func_001288A8(Elem_001287B8* self, int a, float v);

class Elem_001287B8 {
public:
    int m0;
    void SetProps(void* params);
};

void Elem_001287B8::SetProps(void* params)
{
    func_00124868(this, params);
    float v;
    if (func_001E7F50(params, D_0035CDD8, &v, 0)) {
        func_001288A8(this, 0, v);
    }
}
