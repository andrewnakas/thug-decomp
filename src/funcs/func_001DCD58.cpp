struct Entry_001DCD58 {
    char m_pad[0xC];
    char mC[0x3C - 0xC];
};

struct Node_001DCD58 {
    unsigned int m0;
    char m_pad4[0xC - 0x4];
    void* mC;
    Node_001DCD58* m10;
};

extern Node_001DCD58* D_0038E0AC;
extern Entry_001DCD58 D_003EC2F8[42];

extern "C" unsigned int func_0010FC30();
extern "C" bool func_001DD678(void* self, unsigned int id, int* index);
extern "C" void func_001DCE40(void* self, Node_001DCD58* node, int reason);
extern "C" void func_001A37A8(void* obj, void* data);
extern "C" bool func_001DCB18(void* self, void* obj, Entry_001DCD58* entry, unsigned int now);

extern "C" void func_001DCD58(void* self)
{
    Node_001DCD58* p = D_0038E0AC;
    unsigned int now = func_0010FC30();
    while (p) {
        Node_001DCD58* n = p;
        p = p->m10;
        int index;
        if (!func_001DD678(self, n->m0, &index)) {
            func_001DCE40(self, n, 0);
        } else {
            Entry_001DCD58* e = &D_003EC2F8[index];
            func_001A37A8(n->mC, e->mC);
            if (!func_001DCB18(self, n->mC, e, now))
                func_001DCE40(self, n, 1);
        }
    }
}
