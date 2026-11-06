typedef int qword __attribute__((mode(TI)));

struct Mat_00170490 {
    qword r[4];
};

struct Obj_00170490 {
    char pad0[0x40];
    signed char m40;
    char m41;
    unsigned short m42;
    Mat_00170490* m44;
    void Fn(const Mat_00170490* src);
};

void Obj_00170490::Fn(const Mat_00170490* src)
{
    int start;
    if (m42)
        start = m40;
    else
        start = 0;
    for (int i = 0; i < m40; i++)
        m44[start + i] = src[i];
    m42 = !m42;
}
