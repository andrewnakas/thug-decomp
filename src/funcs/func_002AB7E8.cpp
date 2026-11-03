extern void* D_00388A70;
extern char D_00378D00[];
extern "C" void func_0010A8D8(void* pool, void* p);

struct Link_002AB7E8 {
    int m0;
    int m4;
    int m8;
    Link_002AB7E8* mPrev;
    Link_002AB7E8* mNext;
    void* m14;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Link_002AB7E8();
};

Link_002AB7E8::~Link_002AB7E8() {
    m14 = D_00378D00;
    mNext->mPrev = mPrev;
    mPrev->mNext = mNext;
    mPrev = this;
    mNext = this;
}
