struct Item_00299628 {
    char pad0[0x2C];
    Item_00299628* mNext;
};

struct List_00299628 {
    char pad0[0xC];
    Item_00299628* mHead;
    void Visit();
};

extern "C" void func_00298E10(Item_00299628* item);

void List_00299628::Visit() {
    for (Item_00299628* p = mHead; p; p = p->mNext) {
        func_00298E10(p);
    }
}
