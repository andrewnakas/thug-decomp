struct GoalBase_0023C588 {
    char m_pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
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
    virtual void V15();
    virtual void V16();
    virtual bool HasBeaten();
};

struct Goal_0023C588 : GoalBase_0023C588 {
    char m_pad18[0x30 - 0x18];
    int* m30;
    char m_pad34[0x68 - 0x34];
    int m_level;
    int m_group;
};

struct Mgr_0023C588 {
    int m0;
    char m_table[0x44];
    int m_level;
    int m_group;
};

extern void* D_00392068;

extern "C" int func_0023C040(Mgr_0023C588* self);
extern "C" Goal_0023C588* func_00243C18(void* table, int* key, int* out);
extern "C" bool func_002A19A8(void* self);
extern "C" bool func_00246C60(Goal_0023C588* goal);
extern "C" bool func_002458B8(Goal_0023C588* goal);
extern "C" void* func_00244528(Goal_0023C588* goal);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_00243FB0(Goal_0023C588* goal);

void func_0023C588(Mgr_0023C588* self)
{
    void* mgr = D_00392068;
    for (int i = 0; i < func_0023C040(self); i++) {
        int out;
        Goal_0023C588* goal = func_00243C18(self->m_table, &i, &out);
        if ((!func_002A19A8(mgr) || func_00246C60(goal)) && !func_002458B8(goal) && !goal->HasBeaten()) {
            int* locked = goal->m30;
            void* params = func_00244528(goal);
            int level = goal->m_level;
            int group = goal->m_group;
            if (!*locked) {
                if ((level == self->m_level && group == self->m_group) || func_001E8708(params, 0x4E863E93) || func_001E8708(params, 0x981D3AD0)) {
                    func_00243FB0(goal);
                }
            }
        }
    }
}
