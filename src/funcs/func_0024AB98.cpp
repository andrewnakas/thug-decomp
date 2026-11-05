extern char D_00373EC0[];
extern "C" int func_00103F28(const char* fmt);

struct Base_0024AB98 {
    char pad[0x14];
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual int IsDone();
};

struct Obj_0024AB98 : Base_0024AB98 {
    char pad18[0x8C];
    int mA4;
    char padA8[4];
    int mAC;
    char padB0[0xC];
    int mBC;
    bool Run(int id);
};

bool Obj_0024AB98::Run(int id)
{
    if (IsDone() && mAC == id && !mBC && !mA4) {
        func_00103F28(D_00373EC0);
        mBC = 1;
    }
    return true;
}
