struct Elem_002A9C08;
struct Mgr_002A9C08;
extern Mgr_002A9C08* D_00392068;
extern "C" int func_002A19A8(Mgr_002A9C08* m);
extern "C" int func_002A1A38(Mgr_002A9C08* m);
extern "C" int func_002A1968(Mgr_002A9C08* m);
extern "C" Elem_002A9C08* func_002A56E0(Mgr_002A9C08* m);
extern "C" int func_002B1FD8(Elem_002A9C08* e);

bool func_002A9C08()
{
    Mgr_002A9C08* m = D_00392068;
    if (!func_002A19A8(m))
        return false;
    if (func_002A1A38(m))
        return !func_002A1968(m);
    Elem_002A9C08* e = func_002A56E0(m);
    if (e && func_002B1FD8(e))
        return true;
    return false;
}
