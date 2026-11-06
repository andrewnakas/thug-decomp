/* sym: __13Base_00114C30 = 0x00183CF8 */
/* sym: _vt$12Cam_00114C30 = 0x0035C468 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00114C30 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Mat_00114C30 {
    Vec_00114C30 r[4];
    void Identity()
    {
        r[0].x = 1.0f;
        r[0].y = 0.0f;
        r[0].z = 0.0f;
        r[0].w = 0.0f;
        r[1].x = 0.0f;
        r[1].y = 1.0f;
        r[1].z = 0.0f;
        r[1].w = 0.0f;
        r[2].x = 0.0f;
        r[2].y = 0.0f;
        r[2].z = 1.0f;
        r[2].w = 0.0f;
        r[3].x = 0.0f;
        r[3].y = 0.0f;
        r[3].z = 0.0f;
        r[3].w = 1.0f;
    }
};

extern "C" float func_0013B4A0();

struct Base_00114C30 {
    int m0;
    int m4;
    Base_00114C30();
    virtual void V0();
};

struct Cam_00114C30;
extern "C" void func_00114D28(Cam_00114C30* self, float f);

struct Cam_00114C30 : Base_00114C30 {
    char padC[0x50 - 0xC];
    Vec_00114C30 m50;
    Vec_00114C30 m60;
    Mat_00114C30 m70;
    char padB0[0xB8 - 0xB0];
    float m_near;
    float m_far;
    Cam_00114C30();
    virtual void V0();
};

Cam_00114C30::Cam_00114C30()
{
    func_00114D28(this, func_0013B4A0());
    m70.Identity();
    m_near = 12.0f;
    m_far = 12000.0f;
    m60.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m50.Set(0.0f, 0.0f, 0.0f, 1.0f);
}
