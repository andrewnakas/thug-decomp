class Gfx_001387F0 {
public:
    int m0[2];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual int Draw(unsigned short a, unsigned short b, unsigned short c, unsigned short d, int e, unsigned short f, unsigned short g);
    int DrawRect(unsigned short a, unsigned short b, unsigned short c, unsigned short d, int e, unsigned short f, unsigned short g);
};

int Gfx_001387F0::DrawRect(unsigned short a, unsigned short b, unsigned short c, unsigned short d, int e, unsigned short f, unsigned short g)
{
    return Draw(a, b, c, d, e, f, g);
}
