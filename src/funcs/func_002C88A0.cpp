struct Obj_002C88A0 {
    char pad[0x55];
    unsigned char m55;
    char pad56;
    unsigned char m57;
    char pad58[3];
    unsigned char m5B;
    char pad5C;
    unsigned char m5D;
    void GetRange(unsigned char* x0, unsigned char* z0, unsigned char* x1, unsigned char* z1);
};

void Obj_002C88A0::GetRange(unsigned char* x0, unsigned char* z0, unsigned char* x1, unsigned char* z1)
{
    unsigned char ax = m55;
    unsigned char az = m57;
    unsigned char bx = m5B;
    unsigned char bz = m5D;
    if (bx < ax) {
        unsigned char t = ax;
        ax = bx;
        bx = t;
    }
    if (bz < az) {
        unsigned char t = az;
        az = bz;
        bz = t;
    }
    *x0 = ax;
    *z0 = az;
    *x1 = bx;
    *z1 = bz;
}
