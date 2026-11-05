struct Obj_0021D710 {
    char pad[0x18];
    int m18;
};
extern "C" int func_0021B318(void* params);
extern "C" Obj_0021D710* func_0021B348();

bool func_0021D710(void* params, void* script)
{
    int n = func_0021B318(params);
    Obj_0021D710* p = func_0021B348();
    if (p && n < p->m18)
        return true;
    return false;
}
