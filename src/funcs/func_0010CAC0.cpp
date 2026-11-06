struct Item_0010CAC0 {
    Item_0010CAC0* next;
    unsigned int m4;
};

struct Link_0010CAC0 {
    char pad0[0x1C];
    Item_0010CAC0* m1C;
};

extern "C" unsigned int func_0010C258(void* p);

struct Heap_0010CAC0 {
    char pad0[0x34];
    void* m34;
    char pad38[0x40 - 0x38];
    Link_0010CAC0* m40;
    unsigned int MaxUsed();
};

unsigned int Heap_0010CAC0::MaxUsed()
{
    unsigned int best = 0;
    for (Item_0010CAC0* i = m40->m1C; i; i = i->next) {
        if (!(i->m4 < best)) best = i->m4;
    }
    unsigned int r = func_0010C258(m34);
    if (!(best < r)) r = best;
    return r;
}
