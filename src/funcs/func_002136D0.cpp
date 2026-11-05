extern char D_003708E0[];
extern int D_00394138[2];

extern "C" bool func_001E7C80(void* params, int name, int* out, int assert);
extern "C" bool func_001E87B8(void* params, char* flag);
extern "C" int func_00105520(int id);
extern "C" void func_00229340(int id, int on);

bool Cmd_002136D0(void* params, void* script)
{
    int id = 0;
    func_001E7C80(params, 0, &id, 0);
    if (func_001E87B8(params, D_003708E0)) {
        for (int i = 0; i < 2; i++) {
            if (!D_00394138[i]) {
                D_00394138[i] = func_00105520(id);
                break;
            }
        }
        func_00229340(id, 1);
    } else {
        func_00229340(id, 0);
    }
    return true;
}
