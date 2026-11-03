struct Obj_002B22A0 {
    char pad[0x14C];
    int m14C;
};

extern "C" void func_002B22A0(Obj_002B22A0* o) { o->m14C &= ~0x200; }
