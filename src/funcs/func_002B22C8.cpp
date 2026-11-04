struct Elem_002B22C8 {
    char pad0[0x14C];
    unsigned int m14C;
    int State();
};

int Elem_002B22C8::State()
{
    unsigned int f = m14C;
    if (f & 0x800)
        return 0;
    if (f & 0x1000)
        return 1;
    if (f & 0x2000)
        return 2;
    if (f & 0x4000)
        return 3;
    return -1;
}
