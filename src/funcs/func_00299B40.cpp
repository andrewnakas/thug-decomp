struct Item_00299B40 {
    char pad0[0x2C];
    Item_00299B40* mNext;
};

struct List_00299B40 {
    char pad0[0xC];
    Item_00299B40* mHead;
    void Visit();
};

extern "C" void func_00299238(Item_00299B40* item);

void List_00299B40::Visit() {
    for (Item_00299B40* p = mHead; p; p = p->mNext) {
        func_00299238(p);
    }
}
