struct Rgba_0013C438 {
    unsigned char r, g, b, a;
    Rgba_0013C438(const Rgba_0013C438& o) { *this = o; }
};

class Obj_0013C438 {
public:
    int m[5];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6(Rgba_0013C438 c);
    void SetColor(Rgba_0013C438 c);
};

void Obj_0013C438::SetColor(Rgba_0013C438 c)
{
    V6(c);
}
