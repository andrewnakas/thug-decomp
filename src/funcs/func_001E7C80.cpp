struct Struct_001E7C80;

extern "C" int func_001E7B58(Struct_001E7C80*, unsigned int, unsigned int, int*);
extern "C" void func_001E93D0(Struct_001E7C80*, int);

extern "C" int func_001E7C80(Struct_001E7C80* s, unsigned int name, int* out, int assert)
{
    int v;
    if (func_001E7B58(s, name, 3, &v)) {
        *out = v;
        return 1;
    }
    if (func_001E7B58(s, name, 4, &v)) {
        *out = v;
        return 1;
    }
    if (assert)
        func_001E93D0(s, 0);
    return 0;
}
