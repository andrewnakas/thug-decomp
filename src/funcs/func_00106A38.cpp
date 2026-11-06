struct Mgr_00106A38 {
    char pad0[0x20];
    virtual ~Mgr_00106A38();
};

extern Mgr_00106A38* D_00388948;
extern unsigned int D_0038894C;

void func_00106A38()
{
    if (D_0038894C > 1) {
        D_0038894C--;
        return;
    }
    if (D_00388948) delete D_00388948;
    D_00388948 = 0;
    D_0038894C = 0;
}
