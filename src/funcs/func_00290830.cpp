struct Obj_00290830 {
    char pad[0x1C];
    unsigned int m1C;
    unsigned int Flag();
};

unsigned int Obj_00290830::Flag()
{
    return m1C & 1;
}
