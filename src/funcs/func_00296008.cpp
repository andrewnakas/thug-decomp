struct Ent_00296008 {
    unsigned int m0;
    char pad4[0x2A5 - 0x4];
    unsigned char m2A5;
    char pad2A6[0x350 - 0x2A6];
};

struct Mgr_00296008 {
    char pad[0x20];
    Ent_00296008 m20[50];
    Ent_00296008* mA5C0;
    void Remove(Ent_00296008* e);
};

extern "C" void* func_00240850();
extern "C" int func_00292748(Ent_00296008* e);
extern "C" int func_0023F2E8(void* p, int id);
extern "C" void func_0023BB78(void* p, int id);
extern "C" void func_00292630(Ent_00296008* e);
extern "C" void func_00295DF0(Mgr_00296008* m);

void Mgr_00296008::Remove(Ent_00296008* e)
{
    if (e->m2A5) {
        void* p = func_00240850();
        if (func_0023F2E8(p, func_00292748(e)))
            func_0023BB78(p, func_00292748(e));
    }
    func_00292630(e);
    if (mA5C0 == e)
        mA5C0 = 0;
    func_00295DF0(this);
}
