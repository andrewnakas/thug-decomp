typedef int qword __attribute__((mode(TI)));

union Vec_002BB998 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Base_002BB998 {
    int m0;
    int m4;
    int m8;
    virtual Vec_002BB998 GetSize();
};

struct Shape_002BB998 : Base_002BB998 {
    char pad10[0x20 - 0x10];
    Vec_002BB998 pos;
};

struct Cell_002BB998 {
    int m0;
    int m4;
    int m8;
};

struct Grid_002BB998 {
    char pad0[0x30];
    unsigned int m30;
    void Bounds(Vec_002BB998* mx, Vec_002BB998* mn);
};

extern "C" Cell_002BB998* func_002BB3B0(Grid_002BB998* g, int i);
extern "C" Shape_002BB998* func_002B6CF8(int id);

void Grid_002BB998::Bounds(Vec_002BB998* mx, Vec_002BB998* mn)
{
    mn->f.x = 100000.0f;
    mn->f.y = 100000.0f;
    mn->f.z = 100000.0f;
    mn->f.w = 0.0f;
    mx->f.x = -100000.0f;
    mx->f.y = -100000.0f;
    mx->f.z = -100000.0f;
    mx->f.w = 0.0f;
    for (unsigned int k = 0; k < m30; k++) {
        Shape_002BB998* s = func_002B6CF8(func_002BB3B0(this, k)->m8);
        Vec_002BB998 sz = s->GetSize();
        Vec_002BB998 p = s->pos;
        if (p.f.x - sz.f.x * 0.5f < mn->f.x)
            mn->f.x = p.f.x - sz.f.x * 0.5f;
        if (mx->f.x < p.f.x + sz.f.x * 0.5f)
            mx->f.x = p.f.x + sz.f.x * 0.5f;
        if (p.f.z - sz.f.z * 0.5f < mn->f.z)
            mn->f.z = p.f.z - sz.f.z * 0.5f;
        if (mx->f.z < p.f.z + sz.f.z * 0.5f)
            mx->f.z = p.f.z + sz.f.z * 0.5f;
        if (p.f.y < mn->f.y)
            mn->f.y = p.f.y;
        if (mx->f.y < p.f.y + sz.f.y)
            mx->f.y = p.f.y + sz.f.y;
    }
}
