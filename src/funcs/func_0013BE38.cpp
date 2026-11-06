struct Obj_0013BE38 {
    int m0;
    int m4;
    int m8;
    float mC;
};

extern char D_0035E458[];
extern "C" void func_00103F28(const char* msg);

extern "C" Obj_0013BE38* func_0013BE38(Obj_0013BE38* o)
{
    func_00103F28(D_0035E458);
    o->m0 = 0;
    o->m4 = 0;
    o->m8 = 0;
    o->mC = 10000.0f;
    return o;
}
