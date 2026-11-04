struct Elem_002A96E0 {
    char pad0[0x30];
    int m30;
};

struct Obj_002A96E0 {
    char pad0[0x18];
    void* m18;
};

struct Mgr_002A96E0;
extern Mgr_002A96E0* D_00392068;
extern char D_00392130[];
extern "C" Elem_002A96E0* func_002A56E0(Mgr_002A96E0* m);
extern "C" void func_001E7268(void* p, char* name, int v);

bool func_002A96E0(void* params, Obj_002A96E0* o)
{
    Elem_002A96E0* e = func_002A56E0(D_00392068);
    if (e)
        func_001E7268(o->m18, D_00392130, e->m30);
    return true;
}
