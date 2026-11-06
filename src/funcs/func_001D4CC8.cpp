/* sym: __13Base_001D4CC8 = 0x001D33B8 */
/* sym: _vt$13Node_001D4CC8 = 0x003640E0 */
struct Vec_001D4CC8 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Y() const { return y; }
};

struct Mat_001D4CC8 {
    float m[16];
};

extern "C" Mat_001D4CC8* func_00100200(Mat_001D4CC8* m, float x, float y, float z);

struct Base_001D4CC8 {
    int m0;
    int m4;
    int m8;
    Base_001D4CC8();
    virtual ~Base_001D4CC8();
};

struct Node_001D4CC8 : Base_001D4CC8 {
    Vec_001D4CC8 m10;
    Mat_001D4CC8 m20;
    Mat_001D4CC8 m60;
    int mA0;
    Node_001D4CC8();
    virtual void Update();
};

Node_001D4CC8::Node_001D4CC8()
{
    m10.Set(0.0f, 0.0f, 0.0f, 1.0f);
    float s = m10.Y();
    func_00100200(&m20, s, s, s);
    func_00100200(&m60, s, s, s);
    mA0 = 0;
}
