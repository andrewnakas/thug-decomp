struct Obj_002B2F30 {
    char pad0[0x14C];
    unsigned int lo : 7;
    unsigned int flag : 1;
    unsigned long Flag();
};

unsigned long Obj_002B2F30::Flag()
{
    return flag;
}
