typedef int qword_0022BF00 __attribute__((mode(TI)));

union Vec_0022BF00 {
    qword_0022BF00 q;
    struct {
        float x, y, z, w;
    } f;
    void Set(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};

struct Mat_0022BF00 {
    Vec_0022BF00 row[4];
    Mat_0022BF00& operator=(const Mat_0022BF00& o)
    {
        row[0] = o.row[0];
        row[1] = o.row[1];
        row[2] = o.row[2];
        row[3] = o.row[3];
        return *this;
    }
};

struct Obj_0022BF00 {
    char pad0[0x50];
    Vec_0022BF00 m50;
    char pad60[0x10];
    Mat_0022BF00 m70;
};

extern void* D_0038C608;
extern "C" bool func_001E53A0(unsigned int a, int b);
extern "C" Obj_0022BF00* func_00187B48(void* a, unsigned int b);

bool func_0022BF00()
{
    if (func_001E53A0(0xC965E06F, 0)) {
        Obj_0022BF00* o = func_00187B48(D_0038C608, 0xEB17151B);
        if (!o) return true;
        {
            Mat_0022BF00 m;
            m.row[0].f.x = 1.0f;
            m.row[0].f.y = 0.0f;
            m.row[0].f.z = 0.0f;
            m.row[0].f.w = 0.0f;
            m.row[1].f.x = 0.0f;
            m.row[1].f.y = 1.0f;
            m.row[1].f.z = 0.0f;
            m.row[1].f.w = 0.0f;
            m.row[2].f.x = 0.0f;
            m.row[2].f.y = 0.0f;
            m.row[2].f.z = 1.0f;
            m.row[2].f.w = 0.0f;
            m.row[3].f.x = 0.0f;
            m.row[3].f.y = 0.0f;
            m.row[3].f.z = 0.0f;
            m.row[3].f.w = 1.0f;
            o->m70 = m;
            Vec_0022BF00 v;
            Vec_0022BF00* p = &v;
            p->Set(0.0f, 35.0f, 100.0f, 1.0f);
            o->m50 = v;
        }
    }
    return true;
}
