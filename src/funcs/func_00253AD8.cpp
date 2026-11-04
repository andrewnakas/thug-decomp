extern char D_003752D8[];
extern char D_00375300[];
extern char D_00375328[];

extern "C" void func_001829A8(void* self);
extern "C" void* func_001046B0(int size);
extern "C" void func_001047F8(void* task, int priority);
extern "C" void func_002544A8();
extern "C" void func_002544F8();
extern "C" void func_002542B8();

struct Task_00253AD8 {
    char m_base[0x18];
    void* m_vtbl;
    void (*m_func)();
    void* m_data;
};

struct IdxTask_00253AD8 {
    char m_base[0x18];
    void* m_vtbl;
    int m_pad1C[2];
    int m_index;
    void (*m_func)();
    void* m_data;
};

struct Slot_00253AD8 {
    int m_a;
    int m_b;
    int m_c;
};

struct Pair_00253AD8 {
    int m_a;
    int m_b;
};

struct Mgr_00253AD8 {
    char m_base[0x14];
    void* m_vtbl;
    Task_00253AD8* m_task1;
    Task_00253AD8* m_task2;
    int m_pad20[2];
    IdxTask_00253AD8* m_idxTasks[2];
    int m_order[2];
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    Slot_00253AD8 m_slots[2];
    int m_64;
    Pair_00253AD8 m_pairs[32];
    int m_168;
    int m_16C;
    int m_170;
    Mgr_00253AD8* Init();
};

static inline Task_00253AD8* MakeTask_00253AD8(Task_00253AD8* t, void (*func)(), void* data, int priority)
{
    func_001047F8(t, priority);
    t->m_vtbl = D_00375328;
    t->m_func = func;
    t->m_data = data;
    return t;
}

static inline IdxTask_00253AD8* MakeIdxTask_00253AD8(IdxTask_00253AD8* t, void (*func)(), void* data, int index, int priority)
{
    func_001047F8(t, priority);
    t->m_vtbl = D_00375300;
    t->m_index = index;
    t->m_func = func;
    t->m_data = data;
    return t;
}

Mgr_00253AD8* Mgr_00253AD8::Init()
{
    func_001829A8(this);
    m_vtbl = D_003752D8;
    m_task1 = MakeTask_00253AD8((Task_00253AD8*)func_001046B0(0x24), func_002544A8, this, -2000);
    m_task2 = MakeTask_00253AD8((Task_00253AD8*)func_001046B0(0x24), func_002544F8, this, -1000);
    for (int i = 0; i < 2; i++) {
        m_idxTasks[i] = MakeIdxTask_00253AD8((IdxTask_00253AD8*)func_001046B0(0x30), func_002542B8, this, i, -1000);
        m_slots[i].m_a = 0;
        m_slots[i].m_c = 1;
    }
    m_40 = 300;
    m_44 = 50;
    m_168 = 1;
    m_38 = 0;
    m_64 = 0;
    m_16C = 0;
    m_170 = 0;
    int* order = m_order;
    for (int i = 31; i >= 0; i--)
        m_pairs[i].m_b = 0;
    for (int i = 1; i >= 0; i--)
        order[i] = i;
    return this;
}
