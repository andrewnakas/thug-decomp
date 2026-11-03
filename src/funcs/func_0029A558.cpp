struct Item_0029A558 {
    char pad0[0x4];
    Item_0029A558* mNext;
};

struct List_0029A558 {
    char pad0[0x24];
    Item_0029A558* mHead;
    void Visit();
};

extern "C" void func_00299668(Item_0029A558* item);

void List_0029A558::Visit() {
    for (Item_0029A558* p = mHead; p; p = p->mNext) {
        func_00299668(p);
    }
}
