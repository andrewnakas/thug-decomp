struct Obj_0021DCA8 {
    char pad[0xC];
    int mC;
    char pad2[0x5C - 0x10];
    int m5C;
};
extern "C" int func_0021B318(void* params);
extern "C" Obj_0021DCA8* func_0021B348();

bool func_0021DCA8(void* params, void* script)
{
    int n = func_0021B318(params);
    Obj_0021DCA8* p = func_0021B348();
    if (p && p->mC * p->m5C < n)
        return true;
    return false;
}
