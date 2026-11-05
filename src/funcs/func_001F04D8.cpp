struct Obj_001F04D8 {
    char pad0[0xCC];
    int mCC;
};

void Clear_001F04D8(Obj_001F04D8* o)
{
    if (o && (o->mCC & 1)) o->mCC &= ~4;
}
