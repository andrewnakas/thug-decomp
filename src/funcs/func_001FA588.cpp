struct Obj_001FA588 {
    char pad[0x2AC];
    int m2AC;
};

extern "C" int func_001FA648(Obj_001FA588* p);

extern "C" int func_001FA588(Obj_001FA588* p)
{
    if (func_001FA648(p) == 3)
        return 0;
    if (func_001FA648(p) != 1)
        return p->m2AC;
    return 0;
}
