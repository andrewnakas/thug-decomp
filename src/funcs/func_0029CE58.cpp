struct Res_0029CE58 {
    int m0;
    int m4;
    virtual ~Res_0029CE58();
};

struct Obj_0029CE58 {
    char pad0[0xA0];
    Res_0029CE58* mA0;
    void Free();
};

void Obj_0029CE58::Free()
{
    if (mA0) {
        delete mA0;
        mA0 = 0;
    }
}
