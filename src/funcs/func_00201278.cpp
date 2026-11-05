struct Obj_00201278 {
    char pad0[0x4928];
    Obj_00201278* m4928;
};

void Link_00201278(void* unused, Obj_00201278* a, Obj_00201278* b)
{
    a->m4928 = b;
    b->m4928 = a;
}
