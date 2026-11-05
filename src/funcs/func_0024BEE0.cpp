struct Obj_0024BEE0;
extern "C" void func_0024C520(Obj_0024BEE0* self, int a, int b);
extern "C" void func_002448C0(Obj_0024BEE0* self, int a, int b);

struct Obj_0024BEE0 {
    void Fn(int a, int b);
};

void Obj_0024BEE0::Fn(int a, int b)
{
    func_0024C520(this, a, b);
    func_002448C0(this, a, b);
}
