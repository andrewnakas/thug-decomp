struct Obj_0010B4A0 {
    char pad0[0x18];
    virtual ~Obj_0010B4A0();
};

extern "C" void func_0010AFE0(void* self, int a);

struct Owner_0010B4A0 {
    char pad0[0xF8];
    Obj_0010B4A0* mF8;
    int mFC;
    void Release();
};

void Owner_0010B4A0::Release()
{
    if (mF8) {
        func_0010AFE0(this, mFC);
        if (mF8) delete mF8;
        mF8 = 0;
    }
}
