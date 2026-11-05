struct Obj_0024F2C0;
extern void* D_0038FC78;
extern "C" int func_0022EF38(void* p);
extern "C" int func_0024F1D8(Obj_0024F2C0* self);
extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);

struct Obj_0024F2C0 {
    int m0;
    char m_params[4];
    bool Fn();
};

bool Obj_0024F2C0::Fn()
{
    if (!func_0022EF38(D_0038FC78)) return false;
    if (func_0024F1D8(this)) {
        int v;
        func_001E88D8(m_params, 0x48E748B5, &v, 1);
        return v == 1;
    }
    return true;
}
