struct Obj_001A26F8 {
    char pad[0x48];
    unsigned int m48;
    void Set(int b);
};

void Obj_001A26F8::Set(int b)
{
    m48 &= ~0x20000000u;
    unsigned int v = m48;
    if (b) {
        v |= 0x20000000u;
    }
    m48 = v;
}
