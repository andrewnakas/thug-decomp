/* sym: __12Box_002B7E20iiiiii = 0x002BAA28 */
struct Vec_002B7E20 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Box_002B7E20 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    Box_002B7E20(int a = 0, int b = 0, int c = 0, int e = 0, int f = 0, int g = 0);
    void SetPos(int ax, int ay, int az) { x = ax; y = ay; z = az; }
};

struct Bounds_002B7E20 {
    char pad[0x20];
};

struct Board_002B7E20 {
    char pad0[0x352C];
    Box_002B7E20 m352C;
};

extern Board_002B7E20* D_0039274C;

extern "C" void* func_002BDD30(Board_002B7E20* b);
extern "C" void* func_00131DD8(void* p);
extern "C" void func_00102340(Bounds_002B7E20* out, Vec_002B7E20* a, Vec_002B7E20* b);
extern "C" void func_00134548(void* o, Bounds_002B7E20* b, float f, int n);
extern "C" Vec_002B7E20 func_002C02B0(Board_002B7E20* b, Box_002B7E20* box, Vec_002B7E20* out);

extern "C" void func_002B7E20()
{
    void* obj = func_00131DD8(func_002BDD30(D_0039274C));
    if (!obj)
        return;
    Bounds_002B7E20 m;
    {
        Vec_002B7E20 a;
        Vec_002B7E20 b;
        Vec_002B7E20* pa = &a;
        Vec_002B7E20* pb = &b;
        pa->Set(-200000.0f, -200000.0f, -200000.0f, 1.0f);
        pb->Set(200000.0f, 200000.0f, 200000.0f, 1.0f);
        func_00102340(&m, pa, pb);
        func_00134548(obj, &m, 0.0f, 1);
    }
    Box_002B7E20 bx;
    bx = D_0039274C->m352C;
    Vec_002B7E20 b = func_002C02B0(D_0039274C, &bx, 0);
    bx.SetPos(bx.x + bx.w - 1, bx.y, bx.z + bx.d - 1);
    Vec_002B7E20 c = func_002C02B0(D_0039274C, &bx, 0);
    b.x += 60.0f;
    b.z += 60.0f;
    c.x += 60.0f;
    c.z += 60.0f;
    b.y = -100000.0f;
    c.y = 100000.0f;
    Bounds_002B7E20 m2;
    func_00102340(&m2, &b, &c);
    func_00134548(obj, &m2, 0.0f, 0);
}
