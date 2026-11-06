typedef int qword __attribute__((mode(TI)));

struct Mat_001726E0 {
    qword r[4];
    Mat_001726E0& operator=(const Mat_001726E0& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

extern unsigned char D_00394090;

struct Obj_001726E0 {
    char pad0[0x40];
    Mat_001726E0* m40;
    char pad44[0x68 - 0x44];
    int m68;
    char pad6C[0x78 - 0x6C];
    unsigned char m78;
    signed char m79;
    void Fn(const Mat_001726E0* src);
};

void Obj_001726E0::Fn(const Mat_001726E0* src)
{
    if (m78 != D_00394090) {
        m78 = D_00394090;
        m79 = !m79;
    }
    int start = 0;
    if (!m79)
        start = m68;
    Mat_001726E0* d = m40 + start;
    for (int i = 0; i < m68; i++)
        *d++ = *src++;
}
