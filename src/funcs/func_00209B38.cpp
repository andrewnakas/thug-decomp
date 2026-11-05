struct Obj_00209B38 {
    char pad0[0x1030];
    int m1030;
    short m1034;
    short m1036;
    char pad1038[0x2040 - 0x1038];
    int m2040;
    char pad2044[0x2050 - 0x2044];
    int m2050;
    void Reset();
};

void Obj_00209B38::Reset()
{
    m1034 = 0x10;
    m2050 = 0;
    m1030 = 0;
    m2040 = 0;
    m1036 = 0;
}
