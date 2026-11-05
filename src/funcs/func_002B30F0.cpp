struct Obj_002B30F0 {
    char pad[0x14C];
    unsigned int m14C;
};

extern "C" bool func_002B30F0(Obj_002B30F0* o)
{
    unsigned int f = o->m14C & 0x8;
    return f != 0;
}
