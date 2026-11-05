struct Vec_00254DE0 {
    float x, y, z, w;
};

struct Obj_00254DE0 {
    char pad0[0x40];
    int m40;
    int m44;
};

extern Obj_00254DE0* D_00390828;
extern "C" void func_001E4C80(Vec_00254DE0* v);
extern "C" bool func_001E8998(void* params, int name, Vec_00254DE0* out, int required);
extern "C" int func_0033EBE0(float f);

bool Cmd_00254DE0(void* params, void* script)
{
    Vec_00254DE0 v;
    func_001E4C80(&v);
    float scale = 1000.0f;
    func_001E8998(params, 0, &v, 1);
    Obj_00254DE0* o = D_00390828;
    int a = func_0033EBE0(v.y * scale);
    int b = func_0033EBE0(v.z * scale);
    o->m40 = a;
    o->m44 = b;
    return true;
}
