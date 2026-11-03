extern char D_00453140[];

struct Item_0029A608 {
    int m0;
    Item_0029A608* mNext;
};

struct Inner_0029A608 {
    char pad0[0x18];
    void* m18;
};

struct Holder_0029A608 {
    Inner_0029A608* m0;
};

extern "C" void func_00299748(Item_0029A608* item, void* a, void* b, float t);
extern "C" Holder_0029A608* func_002C0368();
extern "C" void func_00133D48(void* p, int v);

struct List_0029A608 {
    char pad0[0x24];
    Item_0029A608* mHead;
    void Reset();
};

void List_0029A608::Reset() {
    for (Item_0029A608* p = mHead; p; p = p->mNext) {
        func_00299748(p, D_00453140, D_00453140, 0.0f);
    }
    func_00133D48(func_002C0368()->m0->m18, 0);
}
