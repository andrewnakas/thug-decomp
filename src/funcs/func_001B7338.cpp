struct Obj_001B7338;
extern "C" void func_001B7288(Obj_001B7338* o, int i);

struct Obj_001B7338 {
    void Method();
};

void Obj_001B7338::Method()
{
    for (int i = 0; i < 2; i++)
        func_001B7288(this, i);
}
