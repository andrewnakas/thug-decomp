struct Goal_0023C8B0 {
    char m_pad[0x14];
    virtual ~Goal_0023C8B0();
    virtual void V1();
    virtual void V2();
    virtual bool IsActive();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual bool Deactivate();
};

struct Mgr_0023C8B0 {
    int m0;
    char m_table[4];
};

extern "C" int func_0023C040(Mgr_0023C8B0* self);
extern "C" Goal_0023C8B0* func_00243C18(void* table, int* key, int* out);
extern "C" bool func_002464A8(Goal_0023C8B0* goal);
extern "C" unsigned int func_00246258(Goal_0023C8B0* goal);
extern "C" void func_00243CD0(void* table, unsigned int* key);

void func_0023C8B0(Mgr_0023C8B0* self)
{
    for (int i = 0; i < func_0023C040(self); i++) {
        int out;
        Goal_0023C8B0* goal = func_00243C18(self->m_table, &i, &out);
        if (goal->IsActive()) {
            goal->Deactivate();
        }
    }
    for (int j = 0; j < func_0023C040(self); j++) {
        int out;
        Goal_0023C8B0* goal = func_00243C18(self->m_table, &j, &out);
        if (func_002464A8(goal)) {
            unsigned int id = func_00246258(goal);
            func_00243CD0(self->m_table, &id);
            delete goal;
        }
    }
}
