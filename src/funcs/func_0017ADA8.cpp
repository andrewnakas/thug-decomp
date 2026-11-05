typedef int qword_0017ADA8 __attribute__((mode(TI)));

struct V_0017ADA8 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_0017ADA8 q;
    };
};

extern char D_003E1080[];
extern float D_00394058;
extern float D_0039405C;
extern float D_00394060;
extern float D_00394064;
extern float D_00394088;
extern float D_0039408C;
extern "C" void func_00323298(V_0017ADA8* out, void* m, V_0017ADA8* v);
extern "C" int func_0016FBD0(V_0017ADA8* pos, float r, int a);

extern "C" bool func_0017ADA8(V_0017ADA8* pos, float r)
{
    V_0017ADA8 v;
    v.q = pos->q;
    v.w = 1.0f;
    func_00323298(&v, D_003E1080, &v);
    float z = v.z;
    float x = v.x;
    float y = v.y;
    if (z - D_00394088 > r) {
        return false;
    }
    if (D_0039408C - z > r) {
        return false;
    }
    float a = D_0039405C * z;
    float b = D_00394064 * y;
    if (a + b > r) {
        return false;
    }
    if (a - b > r) {
        return false;
    }
    a = D_00394058 * z;
    b = D_00394060 * x;
    if (a - b > r || a + b > r) {
        return false;
    }
    return func_0016FBD0(pos, r, 1) == 0;
}
