/* sym: _vt$13Base_0025A878 = 0x00375700 */
extern "C" void* func_001046B0(int size);
extern "C" void* func_00114C30(void* p);

struct Link_0025A878 {
    int m0;
    Link_0025A878* m4;
    int m8;
    Link_0025A878* mC;
    Link_0025A878* m10;
    virtual void V0();
};

struct Base_0025A878 : Link_0025A878 {
    void* m18;
    int m1C;
    int m20;
    char pad24[8];
    int m2C;
    char pad30[8];
    int m38;
    Base_0025A878();
    virtual void V0();
};

Base_0025A878::Base_0025A878()
{
    m4 = this;
    m8 = 0;
    mC = this;
    m10 = this;
    m38 = 0;
    m20 = 0;
    m1C = 0;
    m2C = 0;
    m18 = func_00114C30(func_001046B0(0xC0));
}
