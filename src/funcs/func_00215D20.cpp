extern char D_0038F600[];
extern char D_00370B20[];
extern "C" int func_001E87B8(void* params, char* name);
extern "C" void func_00103F28(char* s);

extern "C" bool func_00215D20(void* params, void* script)
{
    func_001E87B8(params, D_0038F600);
    func_00103F28(D_00370B20);
    return true;
}
