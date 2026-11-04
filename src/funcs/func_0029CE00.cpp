extern char D_00377660[];

struct Snd_0029CE00 {
    char pad[0x10];
    float m10;
};

extern "C" void* func_001046B0(int size);
extern "C" Snd_0029CE00* func_00115390(void* p);
extern "C" void func_00115438(Snd_0029CE00* s, char* name);

struct Obj_0029CE00 {
    char pad[0xA0];
    Snd_0029CE00* mA0;
    void Init();
};

void Obj_0029CE00::Init()
{
    if (mA0)
        return;
    mA0 = func_00115390(func_001046B0(0x18));
    mA0->m10 = 1.2f;
    func_00115438(mA0, D_00377660);
}
