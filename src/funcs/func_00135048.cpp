extern "C" void func_0013C590(void* p);
extern "C" void func_0013C568(void* p, int on);

struct A_00135048 {
    int m0;
    unsigned short m4;
};

struct C_00135048 {
    char pad[0x20];
    void* m20;
    A_00135048* m24;
    void SetVisible(int on);
};

void C_00135048::SetVisible(int on)
{
    if (m24) {
        if (on)
            m24->m4 &= ~4;
        else
            m24->m4 |= 4;
    }
    if (m20) {
        func_0013C590(m20);
        func_0013C568(m20, on);
    }
}
