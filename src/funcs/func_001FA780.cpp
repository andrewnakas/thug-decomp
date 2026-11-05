struct Obj_001FA780 {
    int m0;
    char pad4[0x2C - 0x4];
    int m2C;
    int m30;
    char m34;
    char pad35[0x40 - 0x35];
    int m40;
    Obj_001FA780* Init();
};

Obj_001FA780* Obj_001FA780::Init()
{
    m0 = 0;
    m2C = 0;
    m30 = 0;
    m34 = 0;
    m40 = 0;
    return this;
}
