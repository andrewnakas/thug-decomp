struct Goal_0023F678 {
    char m_pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual bool IsActive();
};

struct Mgr_0023F678 {
    int m0;
    char m_table[4];
};

struct Score_0023F678 {
    char m_pad[0xC];
    int m_mult;
    char m_pad10[0x18 - 0x10];
    int m18;
    char m_pad1C[0x5C - 0x1C];
    int m_base;
};

extern void* D_0038FC78;

extern "C" bool func_0023D1D8(Mgr_0023F678* self);
extern "C" void func_0023F410(Mgr_0023F678* self);
extern "C" int func_0023C040(Mgr_0023F678* self);
extern "C" Goal_0023F678* func_00243C18(void* table, int* key, int* out);
extern "C" bool func_00248710(Goal_0023F678* goal);
extern "C" void func_0024E1A0(Goal_0023F678* goal);
extern "C" void* func_00244528(Goal_0023F678* goal);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void* func_0022DD38(void* self);
extern "C" Score_0023F678* func_00203360(void* skater);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" unsigned int func_00246258(Goal_0023F678* goal);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" void func_001E6AE8(void* self, int flags);
extern "C" bool func_00248760(Goal_0023F678* goal);
extern "C" void* func_001F0750(unsigned int script, void* params, void* object, int a, int b, int c, int d, int e, int f, int g);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" int func_002392B8(Score_0023F678* self);
extern "C" bool func_0023BD18(Mgr_0023F678* self, unsigned int id);
extern "C" void func_001E6B90(void* params, unsigned int name);

void func_0023F678(Mgr_0023F678* self)
{
    if (func_0023D1D8(self)) {
        func_0023F410(self);
        return;
    }
    int target;
    int n = func_0023C040(self);
    for (int i = 0; i < n; i++) {
        int out;
        Goal_0023F678* goal = func_00243C18(self->m_table, &i, &out);
        if (goal->IsActive() && func_00248710(goal)) {
            func_0024E1A0(goal);
            break;
        }
        if (goal->IsActive() && func_001E8708(func_00244528(goal), 0xC63432A7)) {
            void* skater = func_0022DD38(D_0038FC78);
            if (skater) {
                Score_0023F678* score = func_00203360(skater);
                if (score->m18 > 0) {
                    void* p = func_001E6978(func_001190D0(8));
                    func_001E7360(p, 0x9982E501, func_00246258(goal));
                    func_001E7200(p, 0xB9072B65, score->m18);
                    func_001F0210(0x6B755ED8, p, 0, 0, 0);
                    if (p) {
                        func_001E6AE8(p, 3);
                    }
                }
            }
        } else if (goal->IsActive() && func_00248760(goal) && func_001E8708(func_00244528(goal), 0x7100155D)) {
            void* p = func_001E6978(func_001190D0(8));
            func_001E7360(p, 0x9982E501, func_00246258(goal));
            func_001F0750(0x0FEFDA11, p, 0, 0, -1, 0, 0, 0, 0, 0);
            if (p) {
                func_001E6AE8(p, 3);
            }
        } else if (goal->IsActive() && func_001E8708(func_00244528(goal), 0x293B95A7)) {
            void* skater = func_0022DD38(D_0038FC78);
            if (skater) {
                Score_0023F678* score = func_00203360(skater);
                func_001E7DE8(func_00244528(goal), 0xCD66C8AE, &target, 1);
                if (func_002392B8(score) + score->m_mult * score->m_base >= target) {
                    func_001E7200(func_00244528(goal), 0x3DA891B6, func_002392B8(score) + score->m_mult * score->m_base);
                    func_0023BD18(self, func_00246258(goal));
                    func_001E6B90(func_00244528(goal), 0x3DA891B6);
                }
            }
        }
    }
}
