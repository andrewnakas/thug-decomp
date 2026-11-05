extern "C" int func_00202B30(void* p);

struct Obj_002B30C0 {
    char pad0[0x1C];
    void* m1C;
    int State();
};

int Obj_002B30C0::State()
{
    if (!func_00202B30(m1C))
        return 2;
    return 1;
}
