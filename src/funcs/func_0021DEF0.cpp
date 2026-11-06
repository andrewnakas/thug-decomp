struct Obj_0021DEF0;
struct X_0021DEF0 {
    char pad0[0x18];
    Obj_0021DEF0* m18;
};

extern void* D_0038FC78;
extern void* D_00392068;
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0022E358(void* m);
extern "C" bool func_0024F860(void* p);
extern "C" X_0021DEF0* func_002A56E0(void* p);
extern "C" Obj_0021DEF0* func_0022DE70(void* m, int i);
extern "C" void* func_00203EE0(Obj_0021DEF0* o);
extern "C" void* func_00185578(void* o, unsigned int name);
extern "C" void func_001B9DD0(void* c);

bool Cmd_0021DEF0(void* params, void* script)
{
    int idx;
    func_001E7DE8(params, 0x5B8AB877, &idx, 0);
    if (!func_0024F860(func_0022E358(D_0038FC78))) {
        void* mgr = D_00392068;
        Obj_0021DEF0* o = 0;
        if (!idx) {
            X_0021DEF0* x = func_002A56E0(mgr);
            if (x) o = x->m18;
        } else {
            o = func_0022DE70(D_0038FC78, idx);
        }
        if (o) func_001B9DD0(func_00185578(func_00203EE0(o), 0x5E43A604));
    }
    return true;
}
