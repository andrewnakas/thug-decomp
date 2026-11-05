struct Node_00294AE0 {
    int type;
    char pad4[0x30 - 4];
};

struct Obj_00294AE0 {
    char pad0[0x120];
    Node_00294AE0 m120[7];
    char pad[0x2A1 - 0x120 - 0x30 * 7];
    unsigned char m2A1;
    unsigned char m2A2;
    int CurType();
};

int Obj_00294AE0::CurType()
{
    if (m2A1)
        return m120[m2A2].type;
    return 1;
}
