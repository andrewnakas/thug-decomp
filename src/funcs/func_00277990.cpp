extern "C" void* func_001046B0(int size);
extern "C" void* func_00236458(void* p);
extern "C" void func_00236D48(void* p, int id);

struct Info_00277990 {
    char pad[0x18];
    short m18;
};

struct Obj_00277990 {
    char pad[0xC];
    Info_00277990* mC;
    char pad2[0x1C - 0x10];
    void* m1C;
    void Create();
};

void Obj_00277990::Create()
{
    if (m1C)
        return;
    m1C = func_00236458(func_001046B0(0x1548));
    func_00236D48(m1C, mC->m18);
}
