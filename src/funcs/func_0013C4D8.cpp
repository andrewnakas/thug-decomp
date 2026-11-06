struct Rgba_0013C4D8 {
    unsigned char r, g, b, a;
    Rgba_0013C4D8(const Rgba_0013C4D8& o) { *this = o; }
};

class Obj_0013C4D8 {
public:
    int m[5];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual int V9(int a, int b, Rgba_0013C4D8 c);
    int Set(int a, int b, Rgba_0013C4D8 c);
};

int Obj_0013C4D8::Set(int a, int b, Rgba_0013C4D8 c)
{
    return V9(a, b, c);
}
