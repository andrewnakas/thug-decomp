struct Rgba_0013C4A0 {
    unsigned char r, g, b, a;
    Rgba_0013C4A0(const Rgba_0013C4A0& o) { *this = o; }
};

class Obj_0013C4A0 {
public:
    int m[5];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual Rgba_0013C4A0 V7();
    Rgba_0013C4A0 GetColor();
};

Rgba_0013C4A0 Obj_0013C4A0::GetColor()
{
    return V7();
}
