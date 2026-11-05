struct Obj_00249E38;
extern "C" void* func_00249FE0(Obj_00249E38* self);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_00249C58(Obj_00249E38* self);

struct Obj_00249E38 {
    int m0;
    int m4;
    void Fn(int v);
};

void Obj_00249E38::Fn(int v)
{
    m4 = v;
    if (v) {
        func_001F0210(0xBF67A3CF, func_00249FE0(this), 0, 0, 0);
        func_00249C58(this);
    }
}
