struct Tab_00259F30 {
    char pad[0x258];
};

extern "C" void func_00259D70(Tab_00259F30* t);

struct Obj_00259F30 {
    Tab_00259F30* m0;
    void Fn();
};

void Obj_00259F30::Fn()
{
    for (int i = 0; i < 300; i++) func_00259D70(&m0[i]);
}
