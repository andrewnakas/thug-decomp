extern "C" int func_00119818(void* p);

struct Obj_0025BEB8 {
    char pad[0x1C];
    int m1C;
    char pad20[0x5C];
    char m7C[4];
    bool Fn();
};

bool Obj_0025BEB8::Fn()
{
    bool r = false;
    if (m1C) r = func_00119818(m7C) != 0;
    return r;
}
