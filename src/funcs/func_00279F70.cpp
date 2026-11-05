extern "C" void* func_003315B8(void* p, int c, unsigned int n);

struct Obj_00279F70 {
    char pad[0x5C];
    Obj_00279F70* Init();
};

Obj_00279F70* Obj_00279F70::Init()
{
    func_003315B8(this, 0, 0x5C);
    return this;
}
