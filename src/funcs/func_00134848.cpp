struct Rgba_00134848 {
    unsigned char r, g, b, a;
    Rgba_00134848(const Rgba_00134848& o) { *this = o; }
};

class Obj_00134848 {
public:
    int m[160];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual Rgba_00134848 V9();
    Rgba_00134848 GetColor();
};

Rgba_00134848 Obj_00134848::GetColor()
{
    return V9();
}
