extern void* D_00388A70;
extern void* D_0038A634;
extern "C" void func_001448B0(void* list);
extern "C" void* func_001448C0(void* list, int a);
extern "C" void func_00152130(void* list, void** item);
extern "C" void func_0010A8D8(void* heap, void* p);

void func_0014F438()
{
    func_001448B0(D_0038A634);
    void* n = func_001448C0(D_0038A634, 0);
    while (n) {
        void* c = n;
        n = func_001448C0(D_0038A634, 0);
        void* item = c;
        func_00152130(D_0038A634, &item);
        func_0010A8D8(D_00388A70, c);
    }
}
