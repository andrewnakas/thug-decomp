struct Heap_001BBA98 {
    char pad0[0x3EC];
    int m3EC;
};
extern Heap_001BBA98* D_00388A70;
extern "C" void func_0010A950(Heap_001BBA98* heap, int v);
extern "C" void func_0010A9B0(Heap_001BBA98* heap);
extern "C" void* func_001046B0(int size);
extern "C" void func_001047F8(void* self, int pri);
extern "C" void func_001048F0(void* p);
extern "C" void func_00105260(void* list, void* node);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001BC428();
extern "C" void func_001BC448();
extern char D_00363158[];

struct Slot_001BBA98 {
    int m8;
    char listC[0x4C];
    char m58[0x44];
};

struct Mgr_001BBA98 {
    char pad0[0x8];
    Slot_001BBA98 m_slots[2];
};
extern Mgr_001BBA98* D_0038C3C0;

struct Obj_001BBA98;

struct Task_001BBA98 {
    char pad0[0x18];
    void* m_vtbl;
    void* m1C;
    int m20;
    int m_slot;
    void (*m_func)();
    Obj_001BBA98* m_data;
};

static inline void Init_001BBA98(Task_001BBA98* t, int slot, void (*f)(), Obj_001BBA98* d)
{
    func_001047F8(t, -1);
    t->m_slot = slot;
    t->m_vtbl = D_00363158;
    t->m_data = d;
    t->m_func = f;
}

static inline void Register_001BBA98(Task_001BBA98* t)
{
    Mgr_001BBA98* m = D_0038C3C0;
    func_00105260(m->m_slots[t->m_slot].listC, t);
    t->m1C = m->m_slots[t->m_slot].m58;
    t->m20 = m->m_slots[t->m_slot].m8;
}

static inline void Move_001BBA98(Task_001BBA98* t, int slot)
{
    Mgr_001BBA98* m = D_0038C3C0;
    func_001048F0(t);
    Slot_001BBA98* s = &m->m_slots[slot];
    func_00105260(s->listC, t);
    t->m1C = s->m58;
    t->m20 = m->m_slots[slot].m8;
}

struct Obj_001BBA98 {
    char pad0[0xC];
    void* mC;
    char pad10[0x51C - 0x10];
    Task_001BBA98* m51C;
    Task_001BBA98* m520;
    void Fn(int slot);
};

extern "C" void func_001BAD68(void* p, int v);

void Obj_001BBA98::Fn(int slot)
{
    if (!m51C) {
        func_0010A950(D_00388A70, D_00388A70->m3EC);
        Task_001BBA98* t1 = (Task_001BBA98*)func_001046B0(0x30);
        Init_001BBA98(t1, 0, func_001BC428, this);
        m51C = t1;
        Register_001BBA98(t1);
        Task_001BBA98* t2 = (Task_001BBA98*)func_001046B0(0x30);
        Init_001BBA98(t2, 1, func_001BC448, this);
        m520 = t2;
        Register_001BBA98(t2);
        func_0010A9B0(D_00388A70);
    }
    Move_001BBA98(m51C, slot);
    Move_001BBA98(m520, 1);
    void* p = func_00185578(mC, 0x404EB936);
    if (p)
        func_001BAD68(p, m51C->m20);
}
