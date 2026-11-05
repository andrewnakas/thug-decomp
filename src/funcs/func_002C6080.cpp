struct Obj_002C6080;
extern "C" void func_002C5468(Obj_002C6080* o);

struct Obj_002C6080 {
    char pad0[0xB0];
    int mB0;
    void Poll();
};

void Obj_002C6080::Poll()
{
    if (!mB0)
        func_002C5468(this);
}
