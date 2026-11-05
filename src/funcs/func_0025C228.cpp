struct Obj_0025C228;
extern "C" int func_0025D770(Obj_0025C228* self);

struct Obj_0025C228 {
    char pad[0xB60];
    int mB60;
    bool Fn();
};

bool Obj_0025C228::Fn()
{
    bool r = false;
    if (func_0025D770(this)) r = mB60 != 0;
    return r;
}
