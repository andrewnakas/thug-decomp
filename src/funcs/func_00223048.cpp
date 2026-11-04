struct Obj_00223048 {
    char pad0[0x31C];
    int m31C;
};

struct Mgr_00223048 {
    char pad0[0x444];
    int m444[8];
};

extern char D_00371B00[];
extern Mgr_00223048* D_0038FC78;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7E58(void* params, char* name, int* out, int required);
extern "C" Obj_00223048* func_0022DE70(Mgr_00223048* m, int i);

bool Cmd_00223048(void* params, void* script)
{
    int me;
    int val;
    func_001E7DE8(params, 0x5B8AB877, &me, 1);
    func_001E7E58(params, D_00371B00, &val, 1);
    Mgr_00223048* m = D_0038FC78;
    for (int i = 0; i < 8; i++) {
        if (i == me) continue;
        Obj_00223048* o = func_0022DE70(m, i);
        if (o && o->m31C && m->m444[i] == val) return true;
    }
    return false;
}
