struct GoalBase_0023D970 {
    char m_pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void LoadSaveInfo(void* params);
};

struct Comp_0023D970 {
    int m0;
    unsigned int m_name;
    void* m_params;
};

struct Mgr_0023D970 {
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

extern "C" Comp_0023D970* func_001E6E90(void* params, Comp_0023D970* prev);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" bool func_001E53A0(unsigned int name, int a);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int assert_);
extern "C" void func_001E6B30(void* self);
extern "C" void func_001E6AC8(void* self, void* src);
extern "C" void func_0023DEC0(Mgr_0023D970* self);
extern "C" GoalBase_0023D970* func_0023BAD8(Mgr_0023D970* self, unsigned int id, int flag);

void func_0023D970(Mgr_0023D970* self)
{
    Comp_0023D970* comp = func_001E6E90(self->m_params, 0);
    while (comp) {
        Comp_0023D970* next = func_001E6E90(self->m_params, comp);
        if (comp->m_name == 0x23D4170A) {
            func_001E7DE8(comp->m_params, 0x6ABB6FCB, &self->m2C, 0);
            func_001E7DE8(comp->m_params, 0x79ED60AA, &self->m30, 0);
            func_001E7DE8(comp->m_params, 0xF9461A46, &self->m34, 0);
            func_001E7DE8(comp->m_params, 0x875E89BB, &self->m38, 0);
            func_001E7DE8(comp->m_params, 0x46F71D38, &self->m3C, 0);
            if (!func_001E53A0(0x5A1D8804, 0)) {
                func_001E7DE8(comp->m_params, 0xF884773C, &self->m48, 0);
                func_001E7DE8(comp->m_params, 0xAF1575EB, &self->m4C, 0);
            }
            func_001E8398(comp->m_params, 0x7E73362B, &self->m50, 1);
            void* a;
            func_001E8180(comp->m_params, 0x3B1F59E0, &a, 1);
            func_001E6B30(self->m54);
            func_001E6AC8(self->m54, a);
            void* b;
            func_001E8180(comp->m_params, 0xB13D98D3, &b, 1);
            func_001E6B30(self->m5C);
            func_001E6AC8(self->m5C, b);
            int flag;
            func_001E7DE8(comp->m_params, 0x40801D41, &flag, 1);
            if (flag) {
                func_0023DEC0(self);
            }
        } else {
            GoalBase_0023D970* goal = func_0023BAD8(self, comp->m_name, 0);
            if (goal) {
                goal->LoadSaveInfo(comp->m_params);
            }
        }
        comp = next;
    }
    if (self->m40) {
        func_0023DEC0(self);
    }
}
