struct Item_00299FF0 {
    char pad0[0x2C];
    Item_00299FF0* mNext;
};

struct List_00299FF0 {
    char pad0[0xC];
    Item_00299FF0* mHead;
    void Visit();
};

extern "C" void func_002993D8(Item_00299FF0* item);

void List_00299FF0::Visit() {
    for (Item_00299FF0* p = mHead; p; p = p->mNext) {
        func_002993D8(p);
    }
}
