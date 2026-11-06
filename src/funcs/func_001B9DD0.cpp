struct Obj_001B9DD0;
extern "C" void func_001B9978(Obj_001B9DD0* o);

struct Obj_001B9DD0 {
    char pad[0x2C];
    int m2C;
    void Method();
};

void Obj_001B9DD0::Method()
{
    if (m2C < 5) {
        if (++m2C >= 5)
            m2C = 1;
        func_001B9978(this);
    }
}
