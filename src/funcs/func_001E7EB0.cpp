struct Struct_001E7EB0;

extern "C" int func_001E7B58(Struct_001E7EB0*, unsigned int, unsigned int, void*);
extern "C" void func_001E93D0(Struct_001E7EB0*, int);

extern "C" int func_001E7EB0(Struct_001E7EB0* s, unsigned int name, float* out, int assert)
{
    union {
        int i;
        float f;
    } v;
    if (func_001E7B58(s, name, 2, &v)) {
        *out = v.f;
        return 1;
    }
    if (func_001E7B58(s, name, 1, &v)) {
        *out = (float)v.i;
        return 1;
    }
    if (assert)
        func_001E93D0(s, 0);
    return 0;
}
