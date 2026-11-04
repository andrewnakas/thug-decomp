extern char D_0038FF38[];

struct Goal_0023FC30 {
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
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void Reset();
};

struct Mgr_0023FC30 {
    int m0;
    char m_table[4];
};

extern "C" int func_0023C040(Mgr_0023FC30* self);
extern "C" Goal_0023FC30* func_00243C18(void* table, int* key, int* out);
extern "C" bool func_00246740(Goal_0023FC30* goal);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_00248388(Goal_0023FC30* goal, void* params, int a);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int assert_);
extern "C" void* func_00244528(Goal_0023FC30* goal);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int assert_);
extern "C" void func_0023D608(Mgr_0023FC30* self, int value);
extern "C" void func_001E6AE8(void* self, int flags);

void func_0023FC30(Mgr_0023FC30* self)
{
    int n = func_0023C040(self);
    for (int i = 0; i < n; i++) {
        int out;
        Goal_0023FC30* goal = func_00243C18(self->m_table, &i, &out);
        if (!func_00246740(goal) && !goal->HasBeaten()) {
            goal->Reset();
            void* p = func_001E6978(func_001190D0(8));
            func_00248388(goal, p, 1);
            int value;
            if (func_001E7E58(p, D_0038FF38, &value, 0)) {
                const char* name;
                func_001E7C80(func_00244528(goal), 0xBFECC45B, &name, 1);
                func_0023D608(self, value);
            }
            if (p) {
                func_001E6AE8(p, 3);
            }
        }
    }
}
