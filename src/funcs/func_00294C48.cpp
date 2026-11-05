struct Obj_00294C48 {
    char pad0[0x114];
    unsigned int m114;
    char pad118[0x2A2 - 0x118];
    unsigned char m2A2;
    int Extra();
};

int Obj_00294C48::Extra()
{
    int r = 0;
    if (m114 == 0x4EC3CFB5 || m114 == 0x54166ACD)
        r = m2A2 - 2;
    return r;
}
