struct Item_002997B0 {
    char pad0[0x2C];
    Item_002997B0* mNext;
};

struct List_002997B0 {
    char pad0[0xC];
    Item_002997B0* mHead;
    void Visit();
};

extern "C" void func_00298BF8(Item_002997B0* item);

void List_002997B0::Visit() {
    for (Item_002997B0* p = mHead; p; p = p->mNext) {
        func_00298BF8(p);
    }
}
