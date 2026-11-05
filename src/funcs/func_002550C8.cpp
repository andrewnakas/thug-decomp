extern "C" void func_00255AD0(void* p, float v);

struct Obj_002550C8 {
    float* m0;
    char pad[0x18];
    void* m1C;
    bool Fn();
};

bool Obj_002550C8::Fn()
{
    func_00255AD0(m1C, *m0);
    return true;
}
