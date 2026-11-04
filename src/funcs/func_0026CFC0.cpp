extern char D_003913D8[];
extern char D_00376268[];
extern char D_00376278[];
extern "C" int func_001E7DE8(int s, unsigned int id, int* v, int f);
extern "C" int func_001E8870(int s, unsigned int id, char** v, int f);
extern "C" void func_0026CE20(int o, char* name, int a, int score);
extern "C" int func_001E5400(char* name, int d);
extern "C" void func_00103F28(char* fmt, ...);

void func_0026CFC0(int obj, int script)
{
    int score = 0;
    func_001E7DE8(script, 0xCD66C8AE, &score, 0);
    char* name = D_003913D8;
    func_001E8870(script, 0xC4745838, &name, 0);
    if (score && *name) {
        func_0026CE20(obj, name, 0, score);
        return;
    }
    if (func_001E5400(D_00376268, 0)) func_00103F28(D_00376278, name, score);
}
