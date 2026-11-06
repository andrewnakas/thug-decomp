extern char D_00370B10[];
extern "C" bool func_001E8870(void* params, unsigned int name, char** out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_00137FD0(char* s, bool a, bool b);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" void func_00138028(float f);

bool Cmd_00215C00(void* params, void* script)
{
    char* s = D_00370B10;
    func_001E8870(params, 0, &s, 0);
    func_00137FD0(s, func_001E8708(params, 0xB96E0BE5), func_001E8708(params, 0xC3D43B9A));
    float f;
    if (func_001E7EB0(params, 0, &f, 0))
        func_00138028(f);
    return true;
}
