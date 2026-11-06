struct Hook_001147D0 {
    int m0;
    void* m_vt;
    void* m_func;
    void* m_data;
};

struct Task_001147D0 {
    char pad0[0x14];
    int m_prio;
    void* m_vt;
    void* m_func;
    void* m_data;
};

struct Mgr_001147D0 {
    char pad0[0x8];
    char m_list[0xEC - 0x8];
    Hook_001147D0* m_pre;
    Hook_001147D0* m_post;
};

struct Sys_001147D0 {
    int m0;
    Hook_001147D0* m_pre;
    Hook_001147D0* m_post;
    Task_001147D0* m_task;
    int m10;
    int m14;
    int m18;
    int m1C;
};

extern Mgr_001147D0* D_0038C308;
extern char D_0035C3F8[];
extern char D_0035C3D0[];
extern "C" void* func_001046B0(int size);
extern "C" void* func_001047F8(void* self, int a);
extern "C" void func_00105260(void* list, void* node);
extern "C" void func_00114768();
extern "C" void func_00114770();
extern "C" void func_001146D8();

static inline Hook_001147D0* Hook_Init_001147D0(Hook_001147D0* h, void* f, void* d)
{
    h->m_vt = D_0035C3F8;
    h->m_func = f;
    h->m_data = d;
    return h;
}

static inline Task_001147D0* Task_Init_001147D0(Task_001147D0* t, void* f, void* d)
{
    func_001047F8(t, 0);
    t->m_func = f;
    t->m_data = d;
    t->m_vt = D_0035C3D0;
    return t;
}

extern "C" Sys_001147D0* func_001147D0(Sys_001147D0* self)
{
    Mgr_001147D0* mgr = D_0038C308;
    self->m_pre = Hook_Init_001147D0((Hook_001147D0*)func_001046B0(0x10), (void*)func_00114768, self);
    mgr->m_pre = self->m_pre;
    self->m_post = Hook_Init_001147D0((Hook_001147D0*)func_001046B0(0x10), (void*)func_00114770, self);
    mgr->m_post = self->m_post;
    self->m_task = Task_Init_001147D0((Task_001147D0*)func_001046B0(0x24), (void*)func_001146D8, self);
    self->m_task->m_prio = 8;
    func_00105260(mgr->m_list, self->m_task);
    self->m1C = 0;
    self->m10 = 0;
    self->m14 = 0;
    return self;
}
