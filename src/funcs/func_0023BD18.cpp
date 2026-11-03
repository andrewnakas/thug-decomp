struct Info_0023BD18 {
    char m0;
    char m_pad1[3];
    int m4;
};

struct Props_0023BD18 {
    char m0;
    char m1;
    short m2;
    Info_0023BD18* m4;
    int m8;
    int mC;
    char m10;
    char m_pad11[0xF];
};

struct GoalBase_0023BD18 {
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
    virtual bool Activate();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual bool HasBeaten();
};

struct Goal_0023BD18 : GoalBase_0023BD18 {
    char m_pad18[0x2C - 0x18];
    int* m2C;
};

struct Mgr_0023BD18 {
    char m_pad[0x20];
    int m20;
    char m_pad24[0x3C - 0x24];
    int m3C;
};

extern void* D_00392068;

extern "C" Goal_0023BD18* func_0023BAD8(Mgr_0023BD18* self, unsigned int id, int flag);
extern "C" bool func_002A19A8(void* self);
extern "C" Props_0023BD18* func_001FA800(Props_0023BD18* self);
extern "C" void* func_002A39E0(void* self, int a);
extern "C" char func_002A7660(void* self);
extern "C" int func_002461E8(Goal_0023BD18* goal);
extern "C" void func_00200C00(void* self, Props_0023BD18* props);
extern "C" void* func_00244528(Goal_0023BD18* goal);
extern "C" bool func_001E8708(void* params, unsigned int name);

bool func_0023BD18(Mgr_0023BD18* self, unsigned int id)
{
    void* mgr = D_00392068;
    Goal_0023BD18* goal = func_0023BAD8(self, id, 1);
    if (goal) {
        if (!*goal->m2C) {
            self->m20 = 0;
        }
        if (!goal->HasBeaten() && !*goal->m2C) {
            if (func_002A19A8(mgr)) {
                Props_0023BD18 props;
                func_001FA800(&props);
                void* elem = func_002A39E0(mgr, 0);
                Info_0023BD18 info;
                info.m0 = func_002A7660(mgr);
                info.m4 = func_002461E8(goal);
                props.m4 = &info;
                props.m0 = 0x6E;
                props.m2 = 8;
                props.mC = 2;
                props.m10 = 8;
                func_00200C00(elem, &props);
            } else if (!*goal->m2C && !func_001E8708(func_00244528(goal), 0x981D3AD0)) {
                self->m3C++;
            }
        }
        goal->Activate();
    }
    return goal != 0;
}
