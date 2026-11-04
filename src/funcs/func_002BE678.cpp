struct Node_002BE678 {
    char pad[0xC];
    Node_002BE678* mC;
};

extern "C" void* func_002BC5A0(Node_002BE678* n);
extern "C" void* func_002BAB88(void* p);

struct Obj_002BE678 {
    char pad[0x84];
    Node_002BE678* m84;
    char pad88[0x90 - 0x88];
    int m90;
    void* Find(int idx);
};

void* Obj_002BE678::Find(int idx)
{
    int i = m90 - 1;
    for (Node_002BE678* n = m84; n; n = n->mC, i--) {
        void* r = func_002BAB88(func_002BC5A0(n));
        if (i == idx)
            return r;
    }
    return 0;
}
