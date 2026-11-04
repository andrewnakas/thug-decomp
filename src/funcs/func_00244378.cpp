struct Link_00244378 {
    unsigned int m_id;
    Link_00244378* m_next;
};

class Base_00244378 {
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

class Goal_00244378 : public Base_00244378 {
public:
    char pad18[0x14];
    Link_00244378* m_children;
    char pad30[0x40];
    int m70;
};

extern "C" void func_00248800(Goal_00244378* self, unsigned int name);
extern "C" void* func_00240850();
extern "C" Goal_00244378* func_0023BAD8(void* self, unsigned int id, int flag);

extern "C" void func_00244378(Goal_00244378* self, int recurse, int depth)
{
    if (self->IsActive())
        self->Deactivate(1, 1);
    func_00248800(self, 0xD4E0306A);
    self->m70 = 0;
    if (!recurse)
        return;
    void* mgr = func_00240850();
    for (Link_00244378* n = self->m_children; n && n->m_id; n = n->m_next)
        func_00244378(func_0023BAD8(mgr, n->m_id, 1), recurse, depth + 1);
}
