typedef int qword __attribute__((mode(TI)));

union Vec4 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Matrix {
    Vec4 row[4];
    Matrix& operator=(const Matrix& o)
    {
        row[0] = o.row[0];
        row[1] = o.row[1];
        row[2] = o.row[2];
        row[3] = o.row[3];
        return *this;
    }
};

struct Pose {
    Matrix m;
    Vec4 pos;
    float m50;
    float m54;
};

struct Owner {
    char pad[0x95C];
    int m95C;
};

struct Blend {
    char pad[0x1C];
    int m1C;
    int m20;
    float m24;
    int m28;
    int m2C;
};

struct Ctrl_001CDE88 {
    char pad[0x1C];
    int m1C;
    int m20;
    char pad24[4];
    float m28;
    char pad2C[4];
    Vec4 m30;
    Matrix m40;
    float m80;
    int m84;
    char pad88[0xA4 - 0x88];
    Blend* mA4;
    char padA8[0xB4 - 0xA8];
    Owner* mB4;
    void SetPose(Pose* p);
};

void Ctrl_001CDE88::SetPose(Pose* p)
{
    m30 = p->pos;
    m40 = p->m;
    m80 = p->m50;
    m28 = p->m54;
    m20 = 0;
    mB4->m95C = 0;
    m1C = 0;
    mA4->m2C = 0;
    mA4->m1C = 0;
    m84 = 0;
}
