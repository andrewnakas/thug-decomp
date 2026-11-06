struct Rgba_0013BAD8 {
    unsigned char r, g, b, a;
    Rgba_0013BAD8(const Rgba_0013BAD8& o) { *this = o; }
};

class Obj_0013BAD8 {
public:
    int m[13];
    Rgba_0013BAD8 m34;
    int m38;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    void SetColor(Rgba_0013BAD8 c);
};

void Obj_0013BAD8::SetColor(Rgba_0013BAD8 c)
{
    m34 = c;
    V3();
}
