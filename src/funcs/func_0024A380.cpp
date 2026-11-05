struct Obj_0024A380;
extern char D_00373CC0[];
extern char D_00373CB0[];
extern "C" int func_002466E0(Obj_0024A380* self);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_002476C0(Obj_0024A380* self, void* p);

struct Obj_0024A380 {
    char pad[0xA8];
    int mA8;
    void Fn(void* params);
};

void Obj_0024A380::Fn(void* params)
{
    int v = func_002466E0(this);
    func_001E7268(params, D_00373CC0, v);
    func_001E7268(params, D_00373CB0, mA8);
    func_002476C0(this, params);
}
