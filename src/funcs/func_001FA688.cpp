struct Obj_001FA688 {
    char pad0[0x34];
    signed char m34[0x100];
    void Set(unsigned char i, signed char v);
};

void Obj_001FA688::Set(unsigned char i, signed char v)
{
    m34[i] = v;
}
