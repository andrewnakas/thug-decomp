extern unsigned int D_00394138[2];
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" unsigned int func_00105520(const char* s);
extern "C" void func_002294C0(unsigned int name);

bool Cmd_00213778(void* params, void* script)
{
    const char* s = 0;
    func_001E7C80(params, 0, &s, 0);
    unsigned int name = func_00105520(s);
    func_002294C0(name);
    for (int i = 0; i < 2; i++) {
        if (name == D_00394138[i])
            D_00394138[i] = 0;
    }
    return true;
}
