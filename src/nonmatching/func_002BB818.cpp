/* fuzzy: 85.4 */
struct Vec_002BB818 {
    float x, y, z, w;
    Vec_002BB818() {}
    Vec_002BB818(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    void Set(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
    }
};

struct Base_002BB818 {
    int m0;
    int m4;
    int m8;
    virtual Vec_002BB818 GetSize();
};

struct Shape_002BB818 : Base_002BB818 {
    char pad10[0x20 - 0x10];
    Vec_002BB818 pos;
};

struct Cell_002BB818 {
    int m0;
    int m4;
    int m8;
};

struct Grid_002BB818 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
    char pad6[0x30 - 6];
    unsigned int m30;
    void Layout();
};

extern const float D_00392610;
extern const float D_00392614;
extern const float D_00392618;
extern "C" void func_002BB998(Grid_002BB818* g, Vec_002BB818* mx, Vec_002BB818* mn);
extern "C" Cell_002BB818* func_002BB3B0(Grid_002BB818* g, int i);
extern "C" Shape_002BB818* func_002B6CF8(int id);
extern "C" unsigned char* func_002BAA48(Grid_002BB818* g, int i);

void Grid_002BB818::Layout()
{
    Vec_002BB818 mn;
    Vec_002BB818 mx;
    func_002BB998(this, &mx, &mn);
    Vec_002BB818 d(mx.x - mn.x, mx.y - mn.y, mx.z - mn.z, 1.0f);
    m3 = (int)((d.x + 2.0f) / D_00392610);
    m4 = (int)((d.y + 2.0f) / D_00392614);
    m5 = (int)((d.z + 2.0f) / D_00392618);
    if (!*func_002BAA48(this, 4))
        *func_002BAA48(this, 4) = 1;
    for (unsigned int k = 0; k < m30; k++) {
        Shape_002BB818* s = func_002B6CF8(func_002BB3B0(this, k)->m8);
        Vec_002BB818& p = s->pos;
        p.Set(p.x - mn.x - d.x * 0.5f, p.y, p.z - mn.z - d.z * 0.5f);
    }
}
