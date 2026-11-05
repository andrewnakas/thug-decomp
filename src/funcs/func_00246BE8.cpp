extern "C" int func_001E7360(void* p, int a, unsigned int name);

struct Obj_00246BE8 {
    char pad0[0x20];
    void* m20;
    int Get();
};

int Obj_00246BE8::Get()
{
    return func_001E7360(m20, 0, 0x38221DF4);
}
