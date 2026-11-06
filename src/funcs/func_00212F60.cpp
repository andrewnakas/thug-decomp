extern char D_003707A8[];
extern "C" bool func_0013B000(int i);
extern "C" int func_00103F28(char* fmt);

bool Cmd_00212F60(void* params, void* script)
{
    for (int i = 0; i < 2; i++) {
        if (func_0013B000(i))
            func_00103F28(D_003707A8);
    }
    return true;
}
