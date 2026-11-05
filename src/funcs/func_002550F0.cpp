extern "C" void func_00255C10(void* p, int v);

struct Obj_002550F0 {
    int* m0;
    char pad[0x18];
    void* m1C;
    bool Fn();
};

bool Obj_002550F0::Fn()
{
    func_00255C10(m1C, *m0);
    return true;
}
