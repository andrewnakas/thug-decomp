struct Obj_001F6CF8 {
    int m0;
    char pad[0x2C];
    void* m30;
};

extern "C" void func_00329400(Obj_001F6CF8* p);
extern "C" void func_0031EB08(void* p);

extern "C" bool func_001F6CF8(Obj_001F6CF8* p)
{
    if (p->m0)
        func_00329400(p);
    else
        func_0031EB08(p->m30);
    return true;
}
