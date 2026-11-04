extern "C" int func_0021B318(void* params);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

struct Obj_0021DC20 {
    char pad[0xC];
    int mC;
    char pad2[0x5C - 0x10];
    int m5C;
};
extern "C" Obj_0021DC20* func_0021B348();

bool Check_0021DC20(void* params)
{
    int n = 1;
    int v = func_0021B318(params);
    func_001E7DE8(params, 0xB08C5AE8, &n, 0);
    v = v * n;
    Obj_0021DC20* o = func_0021B348();
    if (o && v < o->mC * o->m5C) return true;
    return false;
}
