struct Obj_00213B30;
extern "C" void func_00213A38(Obj_00213B30* o, int* p);

struct Obj_00213B30 {
    char pad0[0x18];
    int m18;
    void Handle(int* p);
};

void Obj_00213B30::Handle(int* p)
{
    if (m18 == p[0]) func_00213A38(this, p + 1);
}
