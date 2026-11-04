struct Item_0029A6B8 {
    char pad0[0x4];
    Item_0029A6B8* mNext;
};

struct List_0029A6B8 {
    char pad0[0x24];
    Item_0029A6B8* mHead;
    void Visit();
};

extern "C" void func_002997F0(Item_0029A6B8* item);

void List_0029A6B8::Visit() {
    for (Item_0029A6B8* p = mHead; p; p = p->mNext) {
        func_002997F0(p);
    }
}
