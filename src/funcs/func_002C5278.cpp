struct Obj_002C5278 {
    char pad[0xA0];
    void* mA0;
};

extern "C" void func_002C7288(void* p, int f);

extern "C" void func_002C5278(Obj_002C5278* o)
{
    if (o->mA0) {
        func_002C7288(o->mA0, 3);
        o->mA0 = 0;
    }
}
