typedef unsigned int u128 __attribute__((mode(TI)));

union Vec4 {
    float v[4];
    u128 q;
};

struct Mat {
    Vec4 row[4];
};

struct Body {
    char pad[0x70];
    Mat m70;
    char pad2[0xC0 - 0xB0];
    Mat mC0;
};

struct Comp {
    char pad[0xC];
    Body* mC;
    void SaveMatrix();
};

void Comp::SaveMatrix()
{
    Body* b = mC;
    Mat* d = &b->mC0;
    *d = b->m70;
}
