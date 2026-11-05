struct Arg_00213B60 {
    void* m0;
    char m4[4];
};
struct Obj_00213B60 {
    char pad[0x18];
    int m18;
    void Check(Arg_00213B60* a);
};
extern "C" int func_00229E30(void* p);
extern "C" void func_00213A38(Obj_00213B60* self, void* p);

void Obj_00213B60::Check(Arg_00213B60* a)
{
    if (m18 == func_00229E30(a->m0))
        func_00213A38(this, a->m4);
}
