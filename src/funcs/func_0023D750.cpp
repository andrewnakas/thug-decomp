struct GoalBase_0023D750 {
    char m_pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void GetSaveInfo(void* params);
};

struct Mgr_0023D750 {
    int m0;
    char m_table[0x18];
    void* m_params;
    char m_pad20[0xC];
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    unsigned int m50;
    void* m54;
    int m58;
    void* m5C;
};

extern void* D_00392068;

extern "C" bool func_002A19A8(void* self);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E77D0(void* params, unsigned int name, void* value);
extern "C" void func_001E6AE8(void* self, int flags);
extern "C" int func_0023C040(Mgr_0023D750* self);
extern "C" GoalBase_0023D750* func_00243C18(void* table, int* key, int* out);
extern "C" void* func_00244528(GoalBase_0023D750* goal);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_00246290(GoalBase_0023D750* goal);
extern "C" unsigned int func_00246258(GoalBase_0023D750* goal);

void func_0023D750(Mgr_0023D750* self)
{
    if (func_002A19A8(D_00392068)) {
        return;
    }
    void* p = func_001E6978(func_001190D0(8));
    func_001E7200(p, 0x6ABB6FCB, self->m2C);
    func_001E7200(p, 0x79ED60AA, self->m30);
    func_001E7200(p, 0xF9461A46, self->m34);
    func_001E7200(p, 0x875E89BB, self->m38);
    func_001E7200(p, 0x46F71D38, self->m3C);
    func_001E7200(p, 0xF884773C, self->m48);
    func_001E7200(p, 0xAF1575EB, self->m4C);
    func_001E7360(p, 0x7E73362B, self->m50);
    func_001E77D0(p, 0x3B1F59E0, self->m54);
    func_001E77D0(p, 0xB13D98D3, self->m5C);
    func_001E7200(p, 0x40801D41, self->m40 != 0);
    func_001E77D0(self->m_params, 0x23D4170A, p);
    if (p) {
        func_001E6AE8(p, 3);
    }
    for (int i = 0; i < func_0023C040(self); i++) {
        int out;
        GoalBase_0023D750* goal = func_00243C18(self->m_table, &i, &out);
        if (!func_001E8708(func_00244528(goal), 0x3D1CAB0B) && !func_00246290(goal)) {
            void* gp = func_001E6978(func_001190D0(8));
            goal->GetSaveInfo(gp);
            func_001E77D0(self->m_params, func_00246258(goal), gp);
            if (gp) {
                func_001E6AE8(gp, 3);
            }
        }
    }
}
