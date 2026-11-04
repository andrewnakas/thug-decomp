struct Goal_0023F9D0 {
    char m_pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual bool IsActive();
};

struct Mgr_0023F9D0 {
    int m0;
    char m_table[4];
};

extern "C" int func_0023C040(Mgr_0023F9D0* self);
extern "C" Goal_0023F9D0* func_00243C18(void* table, int* key, int* out);
extern "C" bool func_00248760(Goal_0023F9D0* goal);
extern "C" void* func_00244528(Goal_0023F9D0* goal);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" unsigned int func_00246258(Goal_0023F9D0* goal);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void* func_001F0750(unsigned int script, void* params, void* object, int a, int b, int c, int d, int e, int f, int g);
extern "C" void func_001E6AE8(void* self, int flags);
extern "C" bool func_00245F90(Goal_0023F9D0* goal);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

void func_0023F9D0(Mgr_0023F9D0* self)
{
    int n = func_0023C040(self);
    for (int i = 0; i < n; i++) {
        int out;
        Goal_0023F9D0* goal = func_00243C18(self->m_table, &i, &out);
        if (goal->IsActive() && func_00248760(goal) && func_001E8708(func_00244528(goal), 0x7100155D)) {
            void* p = func_001E6978(func_001190D0(8));
            func_001E7360(p, 0x9982E501, func_00246258(goal));
            func_001F0750(0x0FEFDA11, p, 0, 0, -1, 0, 0, 0, 0, 0);
            if (p) {
                func_001E6AE8(p, 3);
            }
        }
        if (goal->IsActive() && func_00245F90(goal)) {
            int value;
            if (func_001E7DE8(func_00244528(goal), 0x60B827D5, &value, 0) && value) {
                func_001E7200(func_00244528(goal), 0x60B827D5, 0);
            }
        }
    }
}
