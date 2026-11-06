struct Ref_0016C5D0 {
    int m0;
    int m4;
};

struct Item_0016C5D0 {
    Ref_0016C5D0* m0;
    char pad4[0x60 - 0x4];
    int m60;
};

int func_0016C5D0(Item_0016C5D0* a, Item_0016C5D0* b)
{
    if (!a->m0->m4)
        a->m60 = 0;
    if (!b->m0->m4)
        b->m60 = 0;
    return a->m60 < b->m60 ? 1 : (b->m60 < a->m60 ? -1 : 0);
}
