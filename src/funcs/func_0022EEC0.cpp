extern void* D_00392068;
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_0022EF38(void* self);
extern "C" bool func_002A1998(void* a);

struct Mgr_0022EEC0 {
    bool Check(void* params);
};

bool Mgr_0022EEC0::Check(void* params)
{
    void* p = D_00392068;
    bool r = false;
    if (func_001E8708(params, 0x68910AC6)) {
        if (func_0022EF38(this) || func_002A1998(p)) {
            r = true;
        }
    }
    return r;
}
