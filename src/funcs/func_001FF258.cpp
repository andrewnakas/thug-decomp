struct Obj_001FF258 {
    char pad0[0x5C];
    unsigned int m5C;
    unsigned int m60;
};

bool Less_001FF258(void* unused, Obj_001FF258* o)
{
    return o->m60 > o->m5C;
}
