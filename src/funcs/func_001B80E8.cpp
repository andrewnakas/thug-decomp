struct Sub_001B80E8 {
    char pad[0x70];
    int m70;
};
struct Obj_001B80E8 {
    int m0, m4, m8;
    Sub_001B80E8* mC;
    int* Get();
};

int* Obj_001B80E8::Get()
{
    return &mC->m70;
}
