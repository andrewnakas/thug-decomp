extern bool D_00391ED8;
extern char D_0037A830[];
extern "C" void func_002C7288(void* p, int f);
extern "C" void func_002C9F48(void* p, int f);
extern "C" void func_002BD4B8(void* p, int v);
extern "C" void* func_0029C320();
extern "C" void func_0029A678(void* p);
extern "C" void func_0029A6B8(void* p);
extern "C" int func_00103F28(char* fmt);

struct Obj_002C5370 {
    char pad0[0x80];
    void* m80;
    char pad84[0x1C];
    void* mA0;
    void* mA4;
    char padA8[0x4];
    unsigned int mAC;
    void Quit();
};

void Obj_002C5370::Quit()
{
    mAC = 0xD443A2BC;
    if (mA0) {
        func_002C7288(mA0, 3);
        mA0 = 0;
    }
    if (mA4) {
        func_002C9F48(mA4, 3);
        mA4 = 0;
    }
    func_002BD4B8(m80, 0);
    D_00391ED8 = false;
    func_0029A678(func_0029C320());
    func_0029A6B8(func_0029C320());
    D_00391ED8 = true;
    func_00103F28(D_0037A830);
}
