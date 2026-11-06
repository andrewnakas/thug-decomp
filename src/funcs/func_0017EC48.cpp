struct Obj_0017EC48 {
    int m0;
    int m_flags;
};

extern "C" void func_0017EBF8(Obj_0017EC48* o);
extern "C" void func_0017EC18(Obj_0017EC48* o);
extern "C" void func_0017B4D8();

extern "C" void func_0017EC48(Obj_0017EC48* o, int on)
{
    int was = (o->m_flags >> 1) & 1;
    if (on) {
        func_0017EBF8(o);
    } else {
        func_0017EC18(o);
    }
    if (was != on) {
        func_0017B4D8();
    }
}
