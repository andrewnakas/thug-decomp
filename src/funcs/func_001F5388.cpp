struct Obj_001F5388 {
    char pad[0x48];
    char m48[4];
};

extern "C" void func_001F6500(void* p);
extern "C" void func_0032A5F8(void* p);

extern "C" bool func_001F5388(Obj_001F5388* p)
{
    func_001F6500(p->m48);
    func_0032A5F8(p);
    return true;
}
