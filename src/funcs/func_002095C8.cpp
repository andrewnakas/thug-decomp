struct Target_002095C8 {
    char pad[0xC];
    virtual int v0();
    virtual int v1();
};
struct Obj_002095C8 {
    char pad[0x70];
    Target_002095C8* m70;
    char pad2[0x88 - 0x74];
    signed char m88;
    int Check();
};

int Obj_002095C8::Check()
{
    if (m88)
        return m70->v1();
    return 1;
}
