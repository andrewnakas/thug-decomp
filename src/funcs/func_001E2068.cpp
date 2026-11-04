struct Obj_001E2068 {
    int m0;
    int m4;
};

extern "C" int func_001E23B0(int cmd, unsigned short reg, int val);
extern "C" void func_001E1928();
extern "C" void func_001E2038();

void func_001E2068(Obj_001E2068* o)
{
    if (o) o->m4 = 1;
    int core;
    for (core = 0; core < 2; core++) {
        func_001E23B0(0x8010, core | 0x980, 0x3FFF);
        func_001E23B0(0x8010, core | 0xA80, 0x3FFF);
    }
    core = 0;
    func_001E1928();
    int v = 0;
    func_001E2038();
    for (; core < 2; core++) {
        for (v = 0; v < 24; v++) {
            int r = core | (v << 1);
            func_001E23B0(0x8010, r | 0x300, 0xFF);
            func_001E23B0(0x8010, r | 0x400, 0x1FC0);
        }
    }
}
