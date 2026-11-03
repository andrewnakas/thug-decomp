extern void* D_00388A70;
extern char D_0037CAE8[];
extern "C" void func_0010A8D8(void* pool, void* p);

struct Link_002DB540 {
    int m0;
    int m4;
    int m8;
    Link_002DB540* mPrev;
    Link_002DB540* mNext;
    void* m14;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Link_002DB540();
};

Link_002DB540::~Link_002DB540() {
    m14 = D_0037CAE8;
    mNext->mPrev = mPrev;
    mPrev->mNext = mNext;
    mPrev = this;
    mNext = this;
}
