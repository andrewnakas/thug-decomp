struct Obj_00298E10 {
    char pad0[0x14];
    float m14;
    char pad18[0x20 - 0x18];
    int m20;
    int pad24;
    float m28;
};

extern "C" float func_00298CC8(Obj_00298E10* o);

extern "C" void func_00298E10(Obj_00298E10* o)
{
    if (o->m20)
        o->m14 = func_00298CC8(o) + o->m28;
}
