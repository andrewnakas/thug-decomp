struct Obj_0024F540;
extern void* D_00392068;
extern "C" bool func_002A19A8(void* net);
extern "C" int func_0024F590(Obj_0024F540* self);

struct Obj_0024F540 {
    bool Fn();
};

bool Obj_0024F540::Fn()
{
    bool r = false;
    if (func_002A19A8(D_00392068)) r = func_0024F590(this) > 0;
    return r;
}
