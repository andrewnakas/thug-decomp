struct Item_002997F0 {
    char pad0[0x2C];
    Item_002997F0* mNext;
};

struct List_002997F0 {
    char pad0[0xC];
    Item_002997F0* mHead;
    void Visit();
};

extern "C" void func_00298C60(Item_002997F0* item);

void List_002997F0::Visit() {
    for (Item_002997F0* p = mHead; p; p = p->mNext) {
        func_00298C60(p);
    }
}
