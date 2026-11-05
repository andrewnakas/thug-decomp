struct Obj_001D4D50 {
    char pad[0xC];
    void* mC;
};

extern char D_003640E0[];
extern "C" void func_001DAE18(Obj_001D4D50* p);
extern "C" void func_001D33D8(Obj_001D4D50* p, void* a);

extern "C" void func_001D4D50(Obj_001D4D50* p, void* a)
{
    p->mC = D_003640E0;
    func_001DAE18(p);
    func_001D33D8(p, a);
}
