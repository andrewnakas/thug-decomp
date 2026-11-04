class Base_0023C448 {
public:
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool IsActive();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual bool Deactivate(int flag, int all);
};

struct Mgr_0023C448 {
    int m0;
    char m4[1];
};

extern "C" int func_0023C040(Mgr_0023C448* self);
extern "C" Base_0023C448* func_00243C18(void* list, int* index, unsigned int* key);
extern "C" bool func_00246740(Base_0023C448* goal);

void func_0023C448(Mgr_0023C448* self)
{
    int i;
    unsigned int key;

    for (i = 0; i < func_0023C040(self); i++) {
        Base_0023C448* goal = func_00243C18(self->m4, &i, &key);
        if (func_00246740(goal) && goal->IsActive())
            goal->Deactivate(0, 1);
    }
}
