struct O_00219CB0 {
    int m0, m4, m8, mC, m10, m14;
    virtual void A();
    virtual void B();
    virtual ~O_00219CB0();
};

extern O_00219CB0* D_0038F334;

extern "C" int func_00219CB0()
{
    delete D_0038F334;
    D_0038F334 = 0;
    return 1;
}
