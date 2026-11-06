struct Obj_00249C58;
extern "C" void* func_00249FE0(Obj_00249C58* self);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void func_001DEF68(unsigned int p);

struct Obj_00249C58 {
    void Fn();
};

void Obj_00249C58::Fn()
{
    void* p = func_00249FE0(this);
    unsigned int v = 0;
    if (func_001E8398(p, 0xDC14D454, &v, 0)) {
        func_001E6B90(p, 0xDC14D454);
        if (v) func_001DEF68(v);
    }
}
