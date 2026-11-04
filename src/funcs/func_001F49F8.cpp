typedef int qword __attribute__((mode(TI)));

struct Ent_001F49F8 {
    int m0;
    int m4;
    char pad8[0x1C];
};

struct Obj_001F49F8 {
    char pad0[0x2C];
    Ent_001F49F8 m2C[70];
    char padA04[0xA30 - 0xA04];
    qword mA30;
    qword mA40;
    char padA50[0xC];
    int mA5C;
    char padA60[0x10];
    qword mA70;
    qword mA80;
    int mA90;
    int mA94;
    int mA98;
    void Reset();
};

extern char D_00366210[];
extern "C" unsigned int func_001F0D78(char* s);
extern "C" void func_001F0210(unsigned int name, int a, int b, int c, int d);

void Obj_001F49F8::Reset()
{
    func_001F0210(func_001F0D78(D_00366210), 0, 0, 0, 0);
    for (int i = 0; i < 70; i++) {
        if (!m2C[i].m4 && m2C[i].m0) m2C[i].m0 = 0;
    }
    mA70 = mA80;
    mA30 = mA40;
    mA90 = 0;
    mA94 = 0;
    mA98 = 0;
    mA5C = 0;
}
