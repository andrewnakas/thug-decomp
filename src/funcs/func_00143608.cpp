extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_00144680(void* table);
extern "C" void* func_00144690(void* table, int a);
extern "C" void func_00144740(void* table, void** key);
extern void* D_00388A70;
extern "C" void func_0014F438();
extern void* D_0038A638;

static inline void Remove_00143608(void* key)
{
    func_00144740(D_0038A638, &key);
}

extern "C" void func_00143608()
{
    func_00144680(D_0038A638);
    void* e = func_00144690(D_0038A638, 0);
    while (e) {
        void* cur = e;
        e = func_00144690(D_0038A638, 0);
        Remove_00143608(cur);
        func_0010A8D8(D_00388A70, cur);
    }
    func_0014F438();
}
