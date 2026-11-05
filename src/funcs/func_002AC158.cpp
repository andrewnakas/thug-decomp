struct Info_002AC158 {
    int m0;
};
struct Mgr_002AC158;
struct Item_002AC158;
extern "C" Item_002AC158* func_002A5248(Mgr_002AC158* m, void* id);
extern "C" void func_002B2FC8(Item_002AC158* it, int v);

struct Obj_002AC158 {
    Info_002AC158* m0;
    char pad4[0x14 - 4];
    void* m14;
    char pad18[4];
    Mgr_002AC158* m1C;
    int Run();
};

int Obj_002AC158::Run()
{
    Info_002AC158* info = m0;
    Item_002AC158* it = func_002A5248(m1C, m14);
    if (it)
        func_002B2FC8(it, info->m0);
    return 1;
}
