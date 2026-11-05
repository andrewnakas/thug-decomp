extern "C" void func_0022E6F8(void* p, int v);

struct Obj_00231FC0 {
    int* m0;
    char pad4[0x1C - 0x4];
    void* m1C;
};

bool Cmd_00231FC0(Obj_00231FC0* o)
{
    func_0022E6F8(o->m1C, *o->m0);
    return true;
}
