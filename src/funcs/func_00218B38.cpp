extern char D_0038F6E0[];
extern char D_0038F6E8[];
extern char D_00370E88[];

extern "C" bool func_001E7F50(void* params, char* name, float* out, int assert);
extern "C" bool func_001E7E58(void* params, char* name, int* out, int assert);
extern "C" void func_0013B488(float v);
extern "C" void func_0013B4A8(float v);
extern "C" void func_00132958(bool on);

bool Cmd_00218B38(void* params, void* script)
{
    float a;
    float b;
    int c;
    if (func_001E7F50(params, D_0038F6E0, &a, 0))
        func_0013B488(a);
    if (func_001E7F50(params, D_0038F6E8, &b, 0))
        func_0013B4A8(b);
    if (func_001E7E58(params, D_00370E88, &c, 0))
        func_00132958(c != 0);
    return true;
}
