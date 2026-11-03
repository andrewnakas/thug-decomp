struct Link_0023DB90 {
    unsigned int m_id;
    Link_0023DB90* m_next;
};

class Base_0023DB90 {
public:
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual bool Check(int v);
};

class Goal_0023DB90 : public Base_0023DB90 {
public:
    char pad18[0x18];
    Link_0023DB90* m_parents;
};

struct Mgr_0023DB90 {
    int m0;
    char m4[1];
};

extern "C" int func_0023C040(Mgr_0023DB90* self);
extern "C" Goal_0023DB90* func_00243C18(void* list, int* index, unsigned int* key);

int func_0023DB90(Mgr_0023DB90* self, int v)
{
    int i;
    unsigned int key;

    int count = 0;
    for (i = 0; i < func_0023C040(self); i++) {
        Goal_0023DB90* goal = func_00243C18(self->m4, &i, &key);
        if (!goal->m_parents->m_id && goal->Check(v))
            count++;
    }
    return count;
}
