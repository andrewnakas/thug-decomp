extern void* D_00392068;
extern "C" bool func_002A19A8(void* a);
extern "C" void* func_0022E358(void* self);
extern "C" unsigned int func_0024F6F8(void* a);

struct Mgr_0022EF38 {
    bool Check();
};

bool Mgr_0022EF38::Check()
{
    bool r = false;
    if (func_002A19A8(D_00392068) || func_0024F6F8(func_0022E358(this)) > 1) {
        r = true;
    }
    return r;
}
