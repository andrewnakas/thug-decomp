struct Struct_001E7FA8;

struct Vec_001E7FA8 {
    int m0;
    float x;
    float y;
    float z;
};

struct Out_001E7FA8 {
    float x;
    float y;
    float z;
    float w;
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

extern "C" int func_001E7B58(Struct_001E7FA8*, unsigned int, unsigned int, Vec_001E7FA8**);
extern "C" void func_001E93D0(Struct_001E7FA8*, int);

extern "C" int func_001E7FA8(Struct_001E7FA8* s, unsigned int name, Out_001E7FA8* out, int assert)
{
    Vec_001E7FA8* v;
    if (func_001E7B58(s, name, 6, &v)) {
        out->Set(v->x, v->y, v->z, 1.0f);
        return 1;
    }
    if (assert)
        func_001E93D0(s, 0);
    return 0;
}
