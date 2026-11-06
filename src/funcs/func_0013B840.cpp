/* sym: _vt$13Quad_0013B840 = 0x0035E2B8 */
struct Rgba_0013B840 {
    unsigned char r, g, b, a;
    void Set(unsigned char v) { r = v; g = v; b = v; a = v; }
};

class Quad_0013B840 {
public:
    void* m0;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
    float m18;
    int m1C;
    int m20;
    int m24;
    short m28;
    short m2A;
    int m2C;
    int m30;
    Rgba_0013B840 m34;
    int m38;
    Quad_0013B840(int a);
    virtual ~Quad_0013B840();
};

Quad_0013B840::Quad_0013B840(int a)
{
    m0 = 0;
    m4 = -1.0f;
    m8 = -1.0f;
    mC = 1.0f;
    m10 = 1.0f;
    m14 = -1.0f;
    m18 = -1.0f;
    m1C = 0;
    m20 = 0;
    m28 = 0;
    m2A = 0;
    m34.Set(0x80);
    m38 = a;
    m2C = 1;
    m30 = 0;
}
