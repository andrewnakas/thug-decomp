struct Obj_001FA678 {
    char pad0[0x34];
    signed char m34[0x100];
    signed char Get(unsigned char i);
};

signed char Obj_001FA678::Get(unsigned char i)
{
    return m34[i];
}
