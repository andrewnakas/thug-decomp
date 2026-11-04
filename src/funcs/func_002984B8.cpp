struct Obj_002984B8;
extern "C" void func_00298BF8(Obj_002984B8* o);
extern "C" void func_00298C60(Obj_002984B8* o);
extern "C" void func_0029C360(Obj_002984B8* o);

struct Obj_002984B8 {
    int m0;
    void Destroy(int flags);
};

void Obj_002984B8::Destroy(int flags)
{
    func_00298BF8(this);
    func_00298C60(this);
    if (flags & 1)
        func_0029C360(this);
}
