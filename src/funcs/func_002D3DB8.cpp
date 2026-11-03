extern void* D_00388A70;
extern char D_0037BE48[];
extern "C" void func_0010A8D8(void* pool, void* p);

struct Link_002D3DB8 {
    int m0;
    int m4;
    int m8;
    Link_002D3DB8* mPrev;
    Link_002D3DB8* mNext;
    void* m14;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Link_002D3DB8();
};

Link_002D3DB8::~Link_002D3DB8() {
    m14 = D_0037BE48;
    mNext->mPrev = mPrev;
    mPrev->mNext = mNext;
    mPrev = this;
    mNext = this;
}
