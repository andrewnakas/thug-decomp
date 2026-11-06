extern "C" void* func_003315B8(void* p, int c, unsigned int n);

struct Obj_00279F10 {
    char pad[0x70];
    int m70;
    int m74;
    char pad2[0x90 - 0x78];
    Obj_00279F10* Init();
};

Obj_00279F10* Obj_00279F10::Init()
{
    m70 = 0;
    m74 = 0;
    func_003315B8(this, 0, 0x90);
    return this;
}
