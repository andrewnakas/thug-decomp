extern char D_00373998[];
extern char D_00373938[];
extern char D_0038FFF8[];
extern char D_00373928[];
extern char D_00373958[];
extern char D_00390000[];
extern char D_00390008[];
extern char D_00373948[];
extern char D_00373968[];
extern char D_00373978[];
extern char D_00373988[];

struct GoalBase_002476C0 {
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

struct Goal_002476C0 : GoalBase_002476C0 {
    int m18;
    int m1C;
    void* m20;
    char m_pad24[0x40 - 0x24];
    int m_timesLost;
    int m_timesWon;
    int m_timesStarted;
    int m4C;
    int m50;
};

extern "C" int func_00246650(Goal_002476C0* self);
extern "C" int func_002458B8(Goal_002476C0* self);
extern "C" int func_00245428(Goal_002476C0* self);
extern "C" void func_001E7268(void* params, const char* name, int value);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int assert_);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);

void func_002476C0(Goal_002476C0* self, void* params)
{
    int record = 0;
    func_001E7268(params, D_00373998, func_00246650(self));
    int locked = func_002458B8(self);
    func_001E7268(params, D_00373938, locked);
    int selected = func_00245428(self);
    func_001E7268(params, D_0038FFF8, selected);
    int beaten = self->HasBeaten();
    func_001E7268(params, D_00373928, beaten);
    unsigned int type;
    if (func_001E84E8(self->m20, D_00373958, &type, 0)) {
        if (type == func_001F0D78(D_00390000)) {
            record = self->m4C;
        } else if (type == func_001F0D78(D_00390008)) {
            record = self->m50;
        }
    }
    func_001E7268(params, D_00373948, record);
    func_001E7268(params, D_00373968, self->m_timesLost);
    func_001E7268(params, D_00373978, self->m_timesWon);
    func_001E7268(params, D_00373988, self->m_timesStarted);
    unsigned int value = 0;
    func_001E8398(self->m20, 0xCED8A3A4, &value, 0);
    func_001E7360(params, 0xCED8A3A4, value);
}
