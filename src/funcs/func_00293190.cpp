typedef int qword __attribute__((mode(TI)));

union Vec_00293190 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

extern "C" float sqrtf(float);
extern "C" float func_001E5318(unsigned int, int);

struct Node_00293190 {
    int type;
    char pad4[0xC];
    Vec_00293190 pos;
    float h;
    float b;
    char pad18[0x30 - 0x28];
};

struct Obj_00293190 {
    char pad0[0x120];
    Node_00293190 m120[7];
    char pad[0x2A1 - 0x120 - 0x30 * 7];
    unsigned char m2A1;
    unsigned char m2A2;
    bool Near(Vec_00293190* p);
};

static inline Vec_00293190 Get_00293190(const Vec_00293190& a)
{
    return a;
}

bool Obj_00293190::Near(Vec_00293190* p)
{
    float r1 = func_001E5318(0x71B20276, 0);
    float r2 = func_001E5318(0x4E9755C1, 0);
    for (int k = 0; k < m2A1; k++) {
        if (k == m2A2)
            continue;
        float lim = r1;
        int ct = m120[m2A2].type;
        int kt = m120[k].type;
        if ((ct == 3 && kt == 2) || (ct == 2 && kt == 3))
            lim = r2;
        Vec_00293190 v = Get_00293190(m120[k].pos);
        v.f.y += m120[k].h;
        Vec_00293190 d;
        d.f.x = v.f.x - p->f.x;
        d.f.y = v.f.y - p->f.y;
        d.f.z = v.f.z - p->f.z;
        d.f.w = v.f.w - p->f.w;
        bool in = sqrtf(d.f.x * d.f.x + d.f.y * d.f.y + d.f.z * d.f.z) < lim;
        if (in)
            return true;
    }
    return false;
}
