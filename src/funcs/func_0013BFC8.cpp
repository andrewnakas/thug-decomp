struct Obj_0013BFC8 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern char D_0035E558[];
extern "C" void func_00103F28(const char* msg);

extern "C" Obj_0013BFC8* func_0013BFC8(Obj_0013BFC8* o)
{
    func_00103F28(D_0035E558);
    o->m0 = 0;
    o->m4 = 0;
    o->m8 = 0;
    o->mC = 0;
    return o;
}
