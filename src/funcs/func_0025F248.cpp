struct EntBase_0025F248 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual int IsActive();
    virtual void V8();
    virtual void V9();
    virtual int IsVisible();
};

struct Ent_0025F248 : EntBase_0025F248 {
    int m18;
};

struct Cfg_0025F248 {
    char pad0[0x38];
    int m38;
};

struct Game_0025F248 {
    char pad0[0x3B0];
    unsigned int m3B0;
};

extern Cfg_0025F248* D_00390828;
extern Game_0025F248* D_0038FC78;
extern "C" void func_0025FE50(void* list, int id);
extern "C" long func_0010FA80();

struct Obj_0025F248 {
    char pad0[0x60];
    char m60[0xC0];
    int m120;
    int m124;

    void Add(Ent_0025F248* e);
};

void Obj_0025F248::Add(Ent_0025F248* e)
{
    if (!e) return;
    if (!e->IsActive()) return;
    if (e->IsVisible() && !D_00390828->m38 && D_0038FC78->m3B0 != 0x9F2BAFB7) {
        func_0025FE50(m60, e->m18);
        m120 = func_0010FA80() + 1;
        m124 = 1;
    }
}
