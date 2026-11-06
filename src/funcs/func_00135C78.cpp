struct Rgba_00135C78 {
    unsigned char r, g, b, a;
    Rgba_00135C78(const Rgba_00135C78& o) { *this = o; }
};

class Obj_00135C78 {
public:
    int m[8];
    Rgba_00135C78 m20;
    int m24;
    int m28[4];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    void Set(Rgba_00135C78 c, int v);
};

void Obj_00135C78::Set(Rgba_00135C78 c, int v)
{
    m20 = c;
    m24 = v;
    V3();
}
