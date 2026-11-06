struct Rgba_0013C5E0 {
    unsigned char r, g, b, a;
    Rgba_0013C5E0(const Rgba_0013C5E0& o) { *this = o; }
};

class Obj_0013C5E0 {
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
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual Rgba_0013C5E0 V17();
    Rgba_0013C5E0 GetColor();
};

Rgba_0013C5E0 Obj_0013C5E0::GetColor()
{
    return V17();
}
