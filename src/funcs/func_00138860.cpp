struct Col_00138860 {
    unsigned char r, g, b, a;
    Col_00138860(const Col_00138860& o) { *this = o; }
};

class Gfx_00138860 {
public:
    int m0[2];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual int Draw(unsigned short a, int b, int c, int d, Col_00138860 col);
    int DrawCol(unsigned short a, int b, int c, int d, Col_00138860 col);
};

int Gfx_00138860::DrawCol(unsigned short a, int b, int c, int d, Col_00138860 col)
{
    return Draw(a, b, c, d, col);
}
