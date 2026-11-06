extern char D_00370748[];
extern "C" bool func_001E7F50(void* params, char* name, float* out, int required);
extern "C" void func_001440E0(float f);
extern "C" void func_0013B000(int i);

bool Cmd_00212880(void* params, void* script)
{
    float f = 0.0f;
    func_001E7F50(params, D_00370748, &f, 0);
    func_001440E0(f);
    for (int i = 0; i < 2; i++)
        func_0013B000(i);
    return true;
}
