struct Obj_0021D758 {
    char pad[0x18];
    int m18;
};

extern "C" int func_0021B318();
extern "C" Obj_0021D758* func_0021B348();

extern "C" int func_0021D758()
{
    int n = func_0021B318();
    Obj_0021D758* p = func_0021B348();
    if (p) {
        if (p->m18 < n)
            return 1;
    }
    return 0;
}
