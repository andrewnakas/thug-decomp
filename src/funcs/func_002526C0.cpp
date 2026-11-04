struct Obj_002526C0 {
    char pad0[8];
    int m8;
    int NextId();
};

extern int D_0038FC78;
extern char D_00374DF8[];
extern char D_00374E10[];
extern "C" int func_0022DF08(int m, int id);
extern "C" void func_00103F28(char* fmt, ...);
extern "C" int func_001E5400(char* name, int d);

int Obj_002526C0::NextId()
{
    int id = 0;
    int mgr = D_0038FC78;
    for (int i = 0; i < 8; i++) {
        id = (m8 + i + 1) % 8;
        if (func_0022DF08(mgr, id)) break;
    }
    func_00103F28(D_00374DF8, id);
    if (func_001E5400(D_00374E10, 0)) return 0;
    return id;
}
