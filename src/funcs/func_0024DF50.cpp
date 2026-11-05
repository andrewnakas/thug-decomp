extern "C" void func_001E6D18(void* params, unsigned int name);
extern "C" void func_0012D8B0(void* mgr, unsigned int a, int b, int c, void* s);
extern void* D_00389A30;

struct Ent_0024DF50 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
};

struct Obj_0024DF50 {
    char pad[0x20];
    void* m20;
    char pad24[0x80];
    Ent_0024DF50 mA4[30];
    int m4DC;
    int m4E0;
    int m4E4[30];
    void Fn();
};

void Obj_0024DF50::Fn()
{
    m4DC = 0;
    m4E0 = 0;
    for (int i = 0; i < 30; i++) {
        mA4[i].m10 = 1;
        mA4[i].m0 = 0;
        mA4[i].m4 = 0;
        mA4[i].m8 = 0;
        m4E4[i] = 0;
    }
    func_001E6D18(m20, 0xC93DA683);
    func_0012D8B0(D_00389A30, 0xE35EC715, 1, 1, 0);
}
