struct Obj_00209350 {
    char pad0[0x64];
    short m64;
    short m66;
    void Set(short a, short b);
};

void Obj_00209350::Set(short a, short b)
{
    m64 = a;
    m66 = b;
}
