struct Slot_0010FC90 {
    char m0[0xC814];
    int m_used;
    char padC818[0xC920 - 0xC818];
};

extern int D_0038881C;
extern Slot_0010FC90 D_003973D8[3];

Slot_0010FC90* func_0010FC90()
{
    int count = 3;
    if (D_0038881C)
        count = 1;
    int i;
    for (i = 0; i < count; i++) {
        if (!D_003973D8[i].m_used) {
            D_003973D8[i].m_used = 1;
            return &D_003973D8[i];
        }
    }
    if (!D_0038881C) {
        for (i = 0; i < count; i++) {
        }
    }
    return 0;
}
