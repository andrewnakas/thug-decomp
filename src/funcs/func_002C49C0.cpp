struct Mgr_002C49C0 {
    char pad0[0x14];
    virtual ~Mgr_002C49C0();
};

extern Mgr_002C49C0* D_00392808;
extern unsigned int D_0039280C;

extern "C" void func_002C49C0()
{
    if (D_0039280C > 1) {
        D_0039280C--;
    } else {
        if (D_00392808)
            delete D_00392808;
        D_00392808 = 0;
        D_0039280C = 0;
    }
}
