/* sym: __13Base_001467C8 = 0x00134E38 */
/* sym: _vt$12Obj_001467C8 = 0x0035F090 */
struct Rgba_001467C8 {
    unsigned char r, g, b, a;
    void Set(unsigned char v) { r = v; g = v; b = v; a = v; }
};

struct Mat_001467C8 {
    float m[4][4];
    void Identity()
    {
        m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
        m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
        m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
        m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
    }
};

class Base_001467C8 {
public:
    char pad[0x28];
    Base_001467C8();
    virtual ~Base_001467C8();
};

class Obj_001467C8 : public Base_001467C8 {
public:
    int m2C;
    int m30;
    char pad34[0xC];
    Mat_001467C8 m40;
    Rgba_001467C8 m80;
    int m84;
    int m88;
    Obj_001467C8();
    virtual ~Obj_001467C8();
};

Obj_001467C8::Obj_001467C8()
{
    m30 = 0;
    m80.Set(0x80);
    m88 = 0;
    m40.Identity();
    m84 = 1;
}
