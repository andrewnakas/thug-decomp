extern int D_00391EC4;

struct Obj_00299540;
extern "C" void func_002995D0(Obj_00299540* o);

struct Obj_00299540 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
};

Obj_00299540* func_00299540(Obj_00299540* o)
{
    o->m10 = D_00391EC4++;
    o->mC = 0;
    o->m4 = 0;
    o->m8 = 0;
    func_002995D0(o);
    return o;
}
