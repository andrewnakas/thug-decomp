extern char D_00453140[];

struct Item_0029A598 {
    int m0;
    Item_0029A598* mNext;
};

struct Inner_0029A598 {
    char pad0[0x18];
    void* m18;
};

struct Holder_0029A598 {
    Inner_0029A598* m0;
};

extern "C" void func_002996A8(Item_0029A598* item, void* a, void* b, float t);
extern "C" Holder_0029A598* func_002C0368();
extern "C" void func_00133D48(void* p, int v);

struct List_0029A598 {
    char pad0[0x24];
    Item_0029A598* mHead;
    void Reset();
};

void List_0029A598::Reset() {
    for (Item_0029A598* p = mHead; p; p = p->mNext) {
        func_002996A8(p, D_00453140, D_00453140, 0.0f);
    }
    func_00133D48(func_002C0368()->m0->m18, 0);
}
