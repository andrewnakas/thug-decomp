struct Rgba_001387B0 {
    unsigned char r, g, b, a;
    Rgba_001387B0(const Rgba_001387B0& o) { *this = o; }
};

class Obj_001387B0 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual int V6(int a, int b, int c, Rgba_001387B0 col);
    int Draw(int a, int b, int c, Rgba_001387B0 col);
};

int Obj_001387B0::Draw(int a, int b, int c, Rgba_001387B0 col)
{
    return V6(a, b, c, col);
}
