struct Mgr_00222F08 {
    char pad0[0x444];
    int m444[1];
};

extern Mgr_00222F08* D_0038FC78;
extern char D_00371B00[];
extern char D_00371B10[];
extern char D_00371B28[];
extern "C" bool func_001E7E58(void* params, char* name, int* out, int required);
extern "C" int func_00103F28(char* fmt, ...);
extern "C" void func_00230338(Mgr_00222F08* mgr);

bool Cmd_00222F08(void* params, void* script)
{
    int controller;
    int index;
    func_001E7E58(params, D_00371B00, &controller, 1);
    func_001E7E58(params, D_00371B10, &index, 1);
    func_00103F28(D_00371B28, index, controller);
    D_0038FC78->m444[index] = controller;
    func_00230338(D_0038FC78);
    return true;
}
