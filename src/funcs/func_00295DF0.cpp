struct Item_00295DF0 {
    char pad0[0x2A5];
    unsigned char m2A5;
    char pad2A6[0x350 - 0x2A6];
    unsigned char Active() { return m2A5; }
};

struct Obj_00295DF0 {
    char pad0[0x20];
    Item_00295DF0 m20[50];
    int CountActive();
};

int Obj_00295DF0::CountActive()
{
    int n = 0;
    for (int i = 0; i < 50; i++) {
        if (m20[i].Active())
            n++;
    }
    return n;
}
