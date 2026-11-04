struct Obj_002B1FF8 {
    char pad[0x14C];
    unsigned int m14C;
};

extern "C" bool func_002B1FF8(Obj_002B1FF8* o)
{
    unsigned int f = o->m14C & 0x10000;
    return f != 0;
}
