extern "C" void* func_001046B0(int size);
extern "C" void* func_00267BB8(void* p);
extern "C" void func_00229FF8(void* a, void* out);
extern "C" void func_002676D8(void* o, void* a, void* b);

struct Item_00267C38 {
    char pad[0x50];
    char m50[0x10];
};

void Create_00267C38(void* a, void* b)
{
    Item_00267C38* o = (Item_00267C38*)func_00267BB8(func_001046B0(0x160));
    func_00229FF8(b, o->m50);
    func_002676D8(o, a, b);
}
