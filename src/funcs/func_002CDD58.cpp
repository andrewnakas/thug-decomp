struct Obj_002CDD58 {
    char pad[0xC];
    int mC;
    int m10;
};

extern "C" bool func_002CDD58(Obj_002CDD58* o)
{
    if (o->mC)
        return false;
    return o->m10 == 0;
}
