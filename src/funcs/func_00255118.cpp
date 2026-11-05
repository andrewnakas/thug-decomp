struct Arg_00255118 {
    char pad[0x80];
    int m80;
};

extern "C" void func_00255E98(void* p, Arg_00255118* a, int v);

struct Obj_00255118 {
    Arg_00255118* m0;
    char pad[0x18];
    void* m1C;
    bool Fn();
};

bool Obj_00255118::Fn()
{
    func_00255E98(m1C, m0, m0->m80);
    return true;
}
