extern "C" void func_001E6D18(void* params, unsigned int name);

struct Ent_0024C520 {
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

struct Obj_0024C520 {
    char pad[0x20];
    void* m20;
    char pad24[0x80];
    Ent_0024C520 mA4[30];
    int m4DC;
    int m4E0;
    int m4E4[30];
    void Fn();
};

void Obj_0024C520::Fn()
{
    m4DC = 0;
    m4E0 = 0;
    for (int i = 0; i < 30; i++) {
        mA4[i].m10 = 0;
        mA4[i].m0 = 0;
        mA4[i].m4 = 0;
        mA4[i].m8 = 0;
        mA4[i].m1C = 0;
        mA4[i].m20 = 1;
        mA4[i].m14 = 0;
        m4E4[i] = 0;
    }
    func_001E6D18(m20, 0xC93DA683);
}
