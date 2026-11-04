class GoalBase_00246790 {
public:
    char pad[0x14];
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual bool IsPaused();
};

class Goal_00246790 : public GoalBase_00246790 {
public:
    int pad18[2];
    void* m_params;
};

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" float func_0010FAB8();
extern "C" unsigned int func_0033EBE0(float x);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

void func_00246790(Goal_00246790* goal)
{
    if (goal->IsPaused())
        return;
    int t;
    func_001E7DE8(goal->m_params, 0x5FD80EDC, &t, 0);
    unsigned int ms = t;
    ms += func_0033EBE0(func_0010FAB8() * 1000.0f);
    func_001E7200(goal->m_params, 0x5FD80EDC, ms);
    func_001E7200(goal->m_params, 0x7B1FE9A4, ms / 1000);
    func_001E7200(goal->m_params, 0xB4DB9CB7, (ms / 10) % 100);
}
