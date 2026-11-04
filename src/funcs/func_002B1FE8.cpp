struct Obj_002B1FE8 {
    char pad[0x14C];
    unsigned int m14C;
};

extern "C" bool func_002B1FE8(Obj_002B1FE8* o)
{
    unsigned int f = o->m14C & 0x4;
    return f != 0;
}
