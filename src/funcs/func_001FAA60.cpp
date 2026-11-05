struct Bits_001FAA60 {
    char pad0[0x14];
    int m14;
    int Bytes();
};

int Bits_001FAA60::Bytes()
{
    return (m14 + 7) >> 3;
}
