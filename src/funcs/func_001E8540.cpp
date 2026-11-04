struct Struct_001E8540;

extern "C" int func_001E8398(Struct_001E8540*, unsigned int, void*, int);
extern "C" int func_001E7C80(Struct_001E8540*, unsigned int, int*, int);
extern "C" void* func_00105520(int);

extern "C" int func_001E8540(Struct_001E8540* s, unsigned int name, void** out, int assert)
{
    if (func_001E8398(s, name, out, assert))
        return 1;
    int t = 0;
    if (func_001E7C80(s, name, &t, assert)) {
        *out = func_00105520(t);
        return 1;
    }
    return 0;
}
