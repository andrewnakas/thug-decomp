extern void* D_00388A70;
extern char D_0037C250[];
extern "C" void func_0010A8D8(void* pool, void* p);

struct Link_002D6800 {
    int m0;
    int m4;
    int m8;
    Link_002D6800* mPrev;
    Link_002D6800* mNext;
    void* m14;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Link_002D6800();
};

Link_002D6800::~Link_002D6800() {
    m14 = D_0037C250;
    mNext->mPrev = mPrev;
    mPrev->mNext = mNext;
    mPrev = this;
    mNext = this;
}
