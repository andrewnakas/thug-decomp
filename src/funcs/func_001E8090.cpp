struct Struct_001E8090;

struct Pair_001E8090 {
    int m0;
    float x;
    float y;
};

extern "C" int func_001E7B58(Struct_001E8090*, unsigned int, unsigned int, Pair_001E8090**);
extern "C" void func_001E93D0(Struct_001E8090*, int);

extern "C" int func_001E8090(Struct_001E8090* s, unsigned int name, float* x, float* y, int assert)
{
    Pair_001E8090* v;
    if (func_001E7B58(s, name, 5, &v)) {
        *x = v->x;
        *y = v->y;
        return 1;
    }
    if (assert)
        func_001E93D0(s, 0);
    return 0;
}
