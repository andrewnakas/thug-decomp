/* sym: _vt$13Node_00258700 = 0x003755C8 */
struct Vec_00258700 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_00258700 {
    Vec_00258700 r[4];
    void Identity()
    {
        r[0].x = 1.0f; r[0].y = 0.0f; r[0].z = 0.0f; r[0].w = 0.0f;
        r[1].x = 0.0f; r[1].y = 1.0f; r[1].z = 0.0f; r[1].w = 0.0f;
        r[2].x = 0.0f; r[2].y = 0.0f; r[2].z = 1.0f; r[2].w = 0.0f;
        r[3].x = 0.0f; r[3].y = 0.0f; r[3].z = 0.0f; r[3].w = 1.0f;
    }
};

struct Node_00258700 {
    char pad0[0x20];
    int m20;
    char pad24[0xC];
    Mat_00258700 m30;
    char pad70[0x10];
    Vec_00258700 m80;
    Vec_00258700 m90;
    Vec_00258700 mA0;
    char padB0[0x54];
    Node_00258700(int a);
    virtual void Update();
};

Node_00258700::Node_00258700(int a)
{
    m20 = a;
    m30.Identity();
    m80.Set(0.0f, 0.0f, 0.0f, 1.0f);
    mA0.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m90.Set(0.0f, 0.0f, 0.0f, 1.0f);
}
