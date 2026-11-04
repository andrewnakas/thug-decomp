struct Item_002CC060 {
    char pad0[0x4];
    int m4;
    char pad8[0xC - 0x8];
    int mC;
    char pad10[0x14 - 0x10];
    int m14;
    char pad18[0xE8 - 0x18];
    int mE8;
};

struct Obj_002CC060 {
    int m0;
    Item_002CC060* m4[0x20];
    int m84[0x20];
    void Add(int a, int b, int slot);
};

extern "C" void* func_001046B0(int size);
extern "C" Item_002CC060* func_002CBD30(void* p);

void Obj_002CC060::Add(int a, int b, int slot)
{
    Item_002CC060** arr = m4;
    Item_002CC060** p = &arr[slot];
    *p = func_002CBD30(func_001046B0(0xF0));
    (*p)->m4 = m0++;
    (*p)->mC = a;
    (*p)->m14 = b;
    (*p)->mE8 = slot;
    m84[slot] = 1;
}
