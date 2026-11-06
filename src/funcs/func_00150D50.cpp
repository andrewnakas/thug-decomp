extern void* D_0038A63C;

struct Item_00150D50 {
    char pad0[0x24];
    virtual ~Item_00150D50();
    virtual void F();
};

extern "C" void func_00144A28(void* list);
extern "C" Item_00150D50* func_00144A38(void* list, int a);
extern "C" void func_00144AE8(void* list, Item_00150D50** item);

void func_00150D50()
{
    func_00144A28(D_0038A63C);
    Item_00150D50* n = func_00144A38(D_0038A63C, 0);
    while (n) {
        Item_00150D50* c = n;
        n = func_00144A38(D_0038A63C, 0);
        Item_00150D50* item = c;
        func_00144AE8(D_0038A63C, &item);
        delete c;
    }
}
