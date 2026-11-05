extern int D_0038FBF8;
extern char D_00372708[];
extern char D_00372718[];
extern "C" int func_00331950(char* a, char* b);
extern "C" void func_00229340(char* name, int a);

bool Cmd_0022B6E8(char** args)
{
    char* name = args[0];
    if (!func_00331950(D_00372708, name) || !func_00331950(D_00372718, name)) {
        D_0038FBF8 = 1;
    }
    func_00229340(name, 0);
    return true;
}
