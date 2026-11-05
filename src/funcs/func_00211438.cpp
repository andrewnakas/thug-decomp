struct Arg_00211438 {
    void* m0;
};
struct Obj_00211438 {
    char pad[0x18];
    int m18;
    void Check(Arg_00211438* a);
};
extern "C" int func_00229E30(void* p);
extern "C" void func_00183E48(Obj_00211438* self);

void Obj_00211438::Check(Arg_00211438* a)
{
    if (m18 == func_00229E30(a->m0))
        func_00183E48(this);
}
