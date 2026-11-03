struct Item_00299668 {
    char pad0[0x2C];
    Item_00299668* mNext;
};

struct List_00299668 {
    char pad0[0xC];
    Item_00299668* mHead;
    void Visit();
};

extern "C" void func_00298E50(Item_00299668* item);

void List_00299668::Visit() {
    for (Item_00299668* p = mHead; p; p = p->mNext) {
        func_00298E50(p);
    }
}
