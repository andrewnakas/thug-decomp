struct Obj_002011A0 {
    char pad0[0x78];
    unsigned int m78;
};

extern "C" unsigned int func_002027F0(Obj_002011A0* o);
extern "C" int func_00202800(Obj_002011A0* o);

bool func_002011A0_Check(unsigned int* now, Obj_002011A0* o)
{
    if (*now - o->m78 >= func_002027F0(o) || func_00202800(o))
        return true;
    return false;
}
