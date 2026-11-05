struct Obj_001F09E8 {
    char pad[0xCC];
    int mCC;
};

extern "C" void func_001EE4D8(Obj_001F09E8* p, int a);

extern "C" void func_001F09E8(Obj_001F09E8* p)
{
    if (p && (p->mCC & 1))
        func_001EE4D8(p, 3);
}
