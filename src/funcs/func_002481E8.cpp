extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

struct Obj_002481E8 {
    char pad[0x20];
    void* m20;
    char pad24[0x3C];
    int m60;
    int Fn();
};

int Obj_002481E8::Fn()
{
    int v = 0;
    if (func_001E7DE8(m20, 0x129DAA10, &v, 0)) return v;
    return m60;
}
