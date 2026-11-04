extern "C" void* func_00185578(void* obj, unsigned int name);
extern void* D_0038DB38;

struct Info_001A4130 {
    int m_pad[34];
    int m88;
    int m8C;
};

struct Prof_001A4130 {
    int m_pad[101];
    int m194;
};

struct Comp_001A4130 {
    int m_pad[152];
    Prof_001A4130* m260;
};

extern "C" Info_001A4130* func_001D0638(void* mgr, int id, int flags);
extern "C" int func_001D40D8(int a, int b, int c, void* obj);

struct C_001A4130 {
    int m_pad[3];
    void* mC;
    int m10[3];
    int m1C;
    void Load(int a, int b);
};

void C_001A4130::Load(int a, int b)
{
    if (b) {
        m1C = func_001D40D8(a, b, 1, mC);
    } else {
        Comp_001A4130* c = (Comp_001A4130*)func_00185578(mC, 0x286A8D26);
        Info_001A4130* info = func_001D0638(D_0038DB38, c->m260->m194, 0);
        if (info) {
            m1C = func_001D40D8(a, info->m8C, info->m88, mC);
        } else {
            m1C = func_001D40D8(a, 0, 0, mC);
        }
    }
}
