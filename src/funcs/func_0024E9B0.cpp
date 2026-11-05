struct Obj_0024E9B0;
extern "C" int func_0024EA20(Obj_0024E9B0* self);
extern "C" void* func_00240850();
extern "C" unsigned int func_00246258(Obj_0024E9B0* self);
extern "C" bool func_0023BD18(void* self, unsigned int id);

struct Obj_0024E9B0 {
    char pad[0xB4];
    int mB4;
    int mB8;
    void Fn();
};

void Obj_0024E9B0::Fn()
{
    if (func_0024EA20(this)) {
        mB8++;
        if (mB4 < mB8) {
            void* mgr = func_00240850();
            func_0023BD18(mgr, func_00246258(this));
        }
    }
}
