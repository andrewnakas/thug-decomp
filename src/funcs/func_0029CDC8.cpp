struct Obj_0029CDC8;
extern "C" void func_0029CE58(Obj_0029CDC8* o);
extern "C" void func_0029CE00(Obj_0029CDC8* o);

struct Obj_0029CDC8 {
    void Set(int on);
};

void Obj_0029CDC8::Set(int on)
{
    if (on)
        func_0029CE58(this);
    else
        func_0029CE00(this);
}
