extern "C" void func_00104A80(void* list, int arg, int mask);
extern "C" void func_00104DB0(void* self);

struct Obj105200 {
    int m0;
    int m4;
    int m8;
    char pad[0x3C - 0xC];
    void* m3C;
    void* m40;
    int m44;
    int m48;
    void Run(int arg);
};

void Obj105200::Run(int arg)
{
    m40 = m3C;
    m4++;
    func_00104A80(m3C, arg, m8);
    m4--;
    func_00104DB0(this);
    m44 = 0;
    m48 = 0;
}
