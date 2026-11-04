extern char D_00373928[];
extern char D_00373938[];
extern char D_0038FFF8[];
extern char D_00373948[];
extern char D_00373958[];
extern char D_00390000[];
extern char D_00390008[];
extern char D_00373968[];
extern char D_00373978[];
extern char D_00373988[];

struct GoalBase_002474E8 {
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
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void SetBeaten();
};

struct Goal_002474E8 : GoalBase_002474E8 {
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

extern "C" bool func_001E7E58(void* params, const char* name, int* out, int assert_);
extern "C" void func_00246648(Goal_002474E8* self);
extern "C" void func_00246508(Goal_002474E8* self);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" void func_001E7268(void* params, const char* name, int value);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int assert_);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);

void func_002474E8(Goal_002474E8* self, void* params)
{
    int beaten = 0;
    func_001E7E58(params, D_00373928, &beaten, 1);
    if (beaten) {
        self->SetBeaten();
    }
    int locked = 1;
    func_001E7E58(params, D_00373938, &locked, 1);
    if (!locked) {
        func_00246648(self);
    }
    int selected = 0;
    func_001E7E58(params, D_0038FFF8, &selected, 1);
    if (selected) {
        func_00246508(self);
    }
    int record = 0;
    func_001E7DE8(params, 0xC22A2B72, &record, 1);
    func_001E7268(self->m20, D_00373948, record);
    unsigned int type;
    if (func_001E84E8(self->m20, D_00373958, &type, 0)) {
        if (type == func_001F0D78(D_00390000)) {
            self->m4C = record;
        } else if (type == func_001F0D78(D_00390008)) {
            self->m50 = record;
        }
    }
    func_001E7E58(params, D_00373968, &self->m_timesLost, 1);
    func_001E7E58(params, D_00373978, &self->m_timesWon, 1);
    func_001E7E58(params, D_00373988, &self->m_timesStarted, 1);
    unsigned int value;
    func_001E8398(params, 0xCED8A3A4, &value, 1);
    if (value) {
        func_001E7360(self->m20, 0xCED8A3A4, value);
    }
}
