struct Tab_00122ED8 {
    int w[0x4420 / 4];
};

struct C_00122ED8 {
    int m0;
    int m4;
    char pad8[0x38];
    Tab_00122ED8 m40;
    char* SetTable(char* buf);
};

char* C_00122ED8::SetTable(char* buf)
{
    m40 = *(Tab_00122ED8*)buf;
    buf += sizeof(Tab_00122ED8);
    return buf;
}
