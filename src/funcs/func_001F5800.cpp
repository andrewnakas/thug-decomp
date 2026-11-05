struct Script_001F5800 {
    int m0;
    int m4;
};
extern char D_0038E9D0[];
extern "C" void func_00103F28(char* fmt, ...);

bool Cmd_001F5800(void* params, Script_001F5800* s)
{
    func_00103F28(D_0038E9D0, s->m4);
    return true;
}
