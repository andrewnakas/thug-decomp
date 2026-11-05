struct Obj_001EC940 {
    char pad[0xC];
    unsigned short mC;
    char padE[0x16 - 0xE];
    unsigned char m16[1];
    void Init();
};

void Obj_001EC940::Init()
{
    for (unsigned short i = 0; i < mC; i++)
        m16[i] = i;
}
