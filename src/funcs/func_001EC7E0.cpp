struct Obj_001EC7E0 {
    unsigned char m0;
    unsigned char m1;
    unsigned short Get();
};

unsigned short Obj_001EC7E0::Get()
{
    return m0 | (m1 << 8);
}
