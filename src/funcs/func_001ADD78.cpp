struct Obj_001ADD78;
extern "C" void func_001ADCF0(Obj_001ADD78* o);

struct Obj_001ADD78 {
    char pad[0xA70];
    int mA70;
    int mA74;
    void Method();
};

void Obj_001ADD78::Method()
{
    if (mA70 != -1) {
        if (mA70 == mA74)
            func_001ADCF0(this);
        else if (++mA70 >= 100)
            mA70 = 0;
    }
}
