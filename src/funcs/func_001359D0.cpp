/* sym: _vt$10C_001359D0 = 0x0035D808 */
struct Rgba_001359D0 {
    unsigned char r, g, b, a;
    void Set(unsigned char v) { r = v; g = v; b = v; a = v; }
};

class C_001359D0 {
public:
    int m0;
    void* m4;
    int m8;
    int mC;
    float m10;
    float m14;
    int m18;
    int m1C;
    Rgba_001359D0 m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    C_001359D0(int a);
    virtual ~C_001359D0() = 0;
    virtual void V1();
};

C_001359D0::C_001359D0(int a)
{
    m0 = 0;
    m8 = 0;
    mC = 0;
    m10 = 1.0f;
    m14 = 1.0f;
    m18 = 0;
    m20.Set(0x80);
    m28 = 1;
    m30 = a;
    m24 = 0;
    m2C = 0;
    m34 = 0;
    m4 = 0;
}
