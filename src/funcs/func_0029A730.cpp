struct Item_0029A730 {
    char pad0[0x4];
    Item_0029A730* mNext;
};

struct List_0029A730 {
    char pad0[0x24];
    Item_0029A730* mHead;
    void Visit();
};

extern "C" void func_00299B40(Item_0029A730* item);

void List_0029A730::Visit() {
    for (Item_0029A730* p = mHead; p; p = p->mNext) {
        func_00299B40(p);
    }
}
