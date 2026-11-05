struct Obj_002B2310 {
    char pad[0x14C];
    int m14C;
};

extern "C" void func_002B2310(Obj_002B2310* o) { o->m14C &= ~0x7800; }
