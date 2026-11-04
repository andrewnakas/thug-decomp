extern "C" void* func_002BC5A0(void* n);

struct Item_002BE5F0 {
    char pad0[0x34];
    int m34;
};

extern "C" Item_002BE5F0* func_002BAB88(void* p);

struct Node_002BE5F0 {
    char pad0[0xC];
    Node_002BE5F0* mC;
};

struct Obj_002BE5F0 {
    char pad0[0x84];
    Node_002BE5F0* m84;
    char pad88[0x8];
    int m90;
    Item_002BE5F0* Find(int type, int* outIdx);
};

Item_002BE5F0* Obj_002BE5F0::Find(int type, int* outIdx)
{
    int idx = m90 - 1;
    for (Node_002BE5F0* n = m84; n; n = n->mC, idx--) {
        Item_002BE5F0* p = func_002BAB88(func_002BC5A0(n));
        if (p->m34 == type) {
            if (outIdx) *outIdx = idx;
            return p;
        }
    }
    return 0;
}
