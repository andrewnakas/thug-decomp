struct Rgba_00134808 {
    unsigned char r, g, b, a;
    Rgba_00134808(const Rgba_00134808& o) { *this = o; }
};

class Obj_00134808 {
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
    virtual void V8(Rgba_00134808 c);
    void SetColor(Rgba_00134808 c);
};

void Obj_00134808::SetColor(Rgba_00134808 c)
{
    V8(c);
}
