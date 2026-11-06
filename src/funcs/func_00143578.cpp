extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_00144508(void* table);
extern "C" void* func_00144518(void* table, int a);
extern "C" void func_001445C8(void* table, void** key);
extern "C" void func_00143608();
extern "C" void func_00150D50();
extern void* D_00388A70;
extern void* D_0038A630;

static inline void Remove_00143578(void* key)
{
    func_001445C8(D_0038A630, &key);
}

extern "C" void func_00143578()
{
    func_00144508(D_0038A630);
    void* e = func_00144518(D_0038A630, 0);
    while (e) {
        void* cur = e;
        e = func_00144518(D_0038A630, 0);
        Remove_00143578(cur);
        func_0010A8D8(D_00388A70, cur);
    }
    func_00143608();
    func_00150D50();
}
