class Mgr_00189168 {
public:
    char pad0[0xB21C];
    virtual ~Mgr_00189168();
    virtual void F();
};

extern Mgr_00189168* D_0038C7B0;
extern unsigned int D_0038C7B4;

void func_00189168()
{
    if (D_0038C7B4 > 1) {
        D_0038C7B4--;
        return;
    }
    if (D_0038C7B0)
        delete D_0038C7B0;
    D_0038C7B0 = 0;
    D_0038C7B4 = 0;
}
