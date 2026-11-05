extern "C" void func_002C7370(void* p);

struct Obj_002C70A0 {
    char pad[0xA0];
    void* mA0;
    void Update();
};

void Obj_002C70A0::Update()
{
    if (mA0)
        func_002C7370(mA0);
}
