struct Skater_0021F7A0 {
    char pad0[0x1C];
    int m1C;
};

struct Obj_0021F7A0 {
    char pad0[0xBC];
    Skater_0021F7A0* mBC;
};

extern void* D_0038FC78;
extern "C" bool func_0022EF38(void* mgr);
extern "C" void* func_0022E358(void* mgr);
extern "C" bool func_0024F860(void* p);
extern "C" Skater_0021F7A0* func_0022DE70(void* mgr, int i);
extern "C" bool func_00205CB8(Skater_0021F7A0* s, void* params);

extern "C" bool func_0021F7A0(void* params, Obj_0021F7A0* obj)
{
    if (obj) {
        Skater_0021F7A0* s = obj->mBC;
        if (s && s->m1C == 1)
            return func_00205CB8(s, params);
    }
    if (!func_0022EF38(D_0038FC78))
        return false;
    if (func_0024F860(func_0022E358(D_0038FC78)))
        return false;
    Skater_0021F7A0* s = func_0022DE70(D_0038FC78, 0);
    if (!s)
        return false;
    return func_00205CB8(s, params);
}
