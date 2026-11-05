extern void* D_0038C7B0;
extern "C" void func_00189750(void* mgr, unsigned int a, int id, unsigned int b, int c, int d);

struct Obj_00124118 {
    char pad[0xC];
    unsigned int m_flags;
    char pad10[0x18 - 0x10];
    int m_id;
    int IsShown()
    {
        if (m_flags & 0x4000) {
            return 1;
        }
        return 0;
    }
    void SetShown(int on);
};

void Obj_00124118::SetShown(int on)
{
    if (on == IsShown()) {
        return;
    }
    if (on == 1) {
        m_flags |= 0x4000;
    } else {
        m_flags &= ~0x4000;
    }
    void* mgr = D_0038C7B0;
    if (on == 1) {
        func_00189750(mgr, 0x3056434F, m_id, 0x36B2EE74, 0, 0);
    } else {
        func_00189750(mgr, 0x4A57316B, m_id, 0x36B2EE74, 0, 0);
    }
}
