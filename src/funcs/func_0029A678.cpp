struct Item_0029A678 {
    char pad0[0x4];
    Item_0029A678* mNext;
};

struct List_0029A678 {
    char pad0[0x24];
    Item_0029A678* mHead;
    void Visit();
};

extern "C" void func_002997B0(Item_0029A678* item);

void List_0029A678::Visit() {
    for (Item_0029A678* p = mHead; p; p = p->mNext) {
        func_002997B0(p);
    }
}
