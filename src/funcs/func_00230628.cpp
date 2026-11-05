extern "C" int func_002637B0(void* p, int k);

struct Obj_00230628 {
    char pad0[0x24];
    void* m24;
    int Get();
};

int Obj_00230628::Get()
{
    return func_002637B0(m24, -1);
}
