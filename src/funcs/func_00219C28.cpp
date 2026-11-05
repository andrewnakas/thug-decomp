struct Task_00219C28 {
    char pad0[0x18];
    void* m18;
    void* m1C;
    void* m20;
};

extern Task_00219C28* D_0038F334;
extern char* D_0038C308;
extern char D_0035C1F8[];
extern "C" void func_0020B000();
extern "C" void* func_001046B0(int size);
extern "C" void* func_001047F8(void* self, int a);
extern "C" void func_00105260(void* list, void* node);

static inline Task_00219C28* Init_00219C28(Task_00219C28* t, void* cb, void* data)
{
    func_001047F8(t, 0);
    t->m1C = cb;
    t->m20 = data;
    t->m18 = D_0035C1F8;
    return t;
}

int func_00219C28()
{
    char* mgr = D_0038C308;
    if (D_0038F334) return 1;
    {
        int local = 0;
        Task_00219C28* t = Init_00219C28((Task_00219C28*)func_001046B0(0x24), (void*)func_0020B000, &local);
        D_0038F334 = t;
        func_00105260(mgr + 8, t);
    }
    return 1;
}
