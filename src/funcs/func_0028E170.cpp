extern "C" int func_0010FC30();

struct Flag_0028E170 {
    int m0;
    bool m4;
    int m8;
    void Set(bool b)
    {
        if (m4 != b) {
            m4 = b;
            m8 = func_0010FC30();
        }
    }
};

struct State_0028E170 {
    char pad0[0x24];
    Flag_0028E170 m24;
};

struct Info_0028E170 {
    char pad0[0x200];
    int m200;
};

struct Obj_0028E170 {
    char pad0[0x594];
    Info_0028E170* m594;
    char pad598[0x5B0 - 0x598];
    State_0028E170* m5B0;
    void Check();
};

void Obj_0028E170::Check()
{
    Flag_0028E170* f = &m5B0->m24;
    if (!f->m4 && m594->m200)
        f->Set(true);
}
