typedef int qword_002C42E8 __attribute__((mode(TI)));

extern char D_0037A660[];
extern char D_0037A678[];
extern char D_0037A688[];
extern char D_0037A698[];
extern char D_0037A6A8[];
extern char D_0037A6B8[];
extern char D_00392788[];
extern const float D_00392610;
extern const float D_00392614;
extern const float D_00392618;

union Vec_002C42E8 {
    qword_002C42E8 q;
    float c[4];
    void Set(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
};

struct Array_002C42E8 {
    char pad[0xC];
    int mC;
};

extern "C" void* func_001E55F8(const char* name, int a);
extern "C" void* func_001E93A0(void* p, int i);
extern "C" void* func_001E9378(void* a, int i);
extern "C" bool func_001E8938(void* s, const char* name, float* out, int required);
extern "C" bool func_001E8978(void* s, const char* name, Vec_002C42E8* out, int required);
extern "C" bool func_001E8AA0(void* s, const char* name, Array_002C42E8** out, int required);
extern "C" float* func_001E9328(Array_002C42E8* a, int i);
extern "C" void func_002B85C8(void* p, int n, float a, float b, float c, float d, float e, float f, float g);
extern "C" void func_002B85F0(void* p, Vec_002C42E8* v, int i);

struct Obj_002C42E8 {
    void* m0;
    void Load();
};

void Obj_002C42E8::Load()
{
    Vec_002C42E8 v1;
    Vec_002C42E8 v2;
    Vec_002C42E8 p;
    float a;
    float b;
    float c;
    Array_002C42E8* arr;
    int i = 0;
    void* s = func_001E9378(func_001E93A0(func_001E55F8(D_0037A660, 0), 0), 0);
    func_001E8938(s, D_0037A678, &a, 1);
    func_001E8978(s, D_0037A688, &v1, 1);
    func_001E8938(s, D_0037A698, &b, 1);
    func_001E8978(s, D_0037A6A8, &v2, 1);
    func_001E8938(s, D_0037A6B8, &c, 1);
    func_001E8AA0(s, D_00392788, &arr, 1);
    func_002B85C8(m0, arr->mC, a * v1.c[0], a * v1.c[1], a * v1.c[2], b * v2.c[0], b * v2.c[1], b * v2.c[2], c);
    if (i < arr->mC) {
        do {
            float* f = func_001E9328(arr, i);
            p.Set(f[1] * D_00392610, f[2] * D_00392614, f[3] * D_00392618, 1.0f);
            func_002B85F0(m0, &p, i);
            i++;
        } while (i < arr->mC);
    }
}
