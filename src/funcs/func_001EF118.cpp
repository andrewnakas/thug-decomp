struct Obj_001EF118 {
    char pad0[0x14];
    int m14;
};

int Call_001EF118(Obj_001EF118* o, int (*fn)(int, Obj_001EF118*))
{
    return fn(o->m14, o);
}
