extern char D_00374928[];
extern char D_00374938[];
extern char D_00374950[];

extern "C" void func_001E6AC8(void* p, void* src);
extern "C" void func_001E93D0(void* p, int a);

struct Obj_0024FBD8 {
    int m_0;
    char m_params[4];

    bool Load(void* params);
};

extern "C" void func_0024EE20(Obj_0024FBD8* self, const char* name, void* params);
extern "C" void func_0024EC78(Obj_0024FBD8* self);
extern "C" void func_0024ED30(Obj_0024FBD8* self);

bool Obj_0024FBD8::Load(void* params)
{
    func_0024EE20(this, D_00374928, params);
    func_0024EE20(this, D_00374938, params);
    func_0024EE20(this, D_00374950, params);
    func_001E6AC8(m_params, params);
    func_0024EC78(this);
    func_0024ED30(this);
    func_001E93D0(m_params, 0);
    return true;
}
