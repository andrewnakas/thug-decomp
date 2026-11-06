struct Item_0016C590 {
    int m0;
};

struct Slot_0016C590 {
    Item_0016C590* m0;
    char pad4[0x70 - 0x4];
};

extern unsigned int D_0038BC1C;
extern Slot_0016C590 D_003E0AA0[12];

void func_0016C590(Item_0016C590* item)
{
    if (D_0038BC1C < 12) {
        D_003E0AA0[D_0038BC1C].m0 = item;
        item->m0 = 1;
        D_0038BC1C++;
    }
}
