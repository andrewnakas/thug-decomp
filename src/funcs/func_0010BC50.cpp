struct Slot_0010BC50 {
    int m0;
    int m4;
    int m8;
    char padC[0x8C - 0xC];
    int m8C;
};

struct Obj_0010BC50 {
    char pad0[0x1A8];
    Slot_0010BC50 slots[4];
    Slot_0010BC50* Find(int key);
};

Slot_0010BC50* Obj_0010BC50::Find(int key)
{
    for (int i = 0; i < 4; i++) {
        if (slots[i].m8C && slots[i].m8 == key) return &slots[i];
    }
    return 0;
}
