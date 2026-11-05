/* sym: _vt$12Fog_00145548 = 0x0035F028 */
struct Rgba_00145548 {
    unsigned char r, g, b, a;
    void Set(unsigned char ar, unsigned char ag, unsigned char ab, unsigned char aa)
    {
        r = ar;
        g = ag;
        b = ab;
        a = aa;
    }
};

class Fog_00145548 {
public:
    float m0;
    int m4;
    float m8;
    int mC;
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
    unsigned char m13;
    unsigned char m14;
    unsigned char m15;
    unsigned char m16;
    unsigned char m17;
    int m18;
    int m1C;
    float m20;
    unsigned char m24;
    unsigned char m25;
    unsigned char m26;
    unsigned char m27;
    int m28;
    int m2C;
    float m30;
    int m34;
    float m38;
    int m3C;
    unsigned char m40;
    unsigned char m41;
    unsigned char m42;
    unsigned char m43;
    int m44;
    Fog_00145548();
    virtual ~Fog_00145548();
};

Fog_00145548::Fog_00145548()
{
    m0 = 2000.0f;
    m4 = 40;
    m8 = 100.0f;
    mC = 0;
    m10 = 0;
    m11 = 0;
    m12 = 0;
    m13 = 0;
    m14 = 255;
    m15 = 255;
    m16 = 255;
    m17 = 255;
    m18 = 0;
    m1C = 8;
    m20 = 16.0f;
    m24 = 128;
    m25 = 128;
    m26 = 128;
    m27 = 128;
    m30 = 500.0f;
    m34 = 254;
    m38 = 4.0f;
    m3C = 0;
    m40 = 128;
    m41 = 128;
    m42 = 128;
    m43 = 128;
    m44 = 1;
    m2C = 0;
}
