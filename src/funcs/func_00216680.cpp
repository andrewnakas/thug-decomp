extern char D_0038F610[];
extern char D_00370B58[];
extern void* D_00392068;
extern "C" int func_001E8890(void* params, void* name, char** out, int req);
extern "C" int func_00331BB8(char* s);
extern "C" int func_00336228(char* s, char* t);
extern "C" void func_002A8110(void* o, char* s);

bool func_00216680(void* params, void* script)
{
    char* s = 0;
    func_001E8890(params, D_0038F610, &s, 0);
    if (!s)
        return false;
    if (func_00331BB8(s) && func_00336228(s, D_00370B58))
        func_002A8110(D_00392068, s);
    return true;
}
