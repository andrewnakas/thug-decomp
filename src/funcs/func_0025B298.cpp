extern "C" int func_00119818(void* p);

struct Obj_0025B298 {
    char pad[0x1C];
    int m1C;
    char pad20[4];
    int m24;
    char pad28[0x18];
    char m40[4];
    int Fn();
};

int Obj_0025B298::Fn()
{
    if (m24) return 1;
    if (m1C) return 0;
    return func_00119818(m40);
}
