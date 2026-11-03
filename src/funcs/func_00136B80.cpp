typedef int qword __attribute__((mode(TI)));

struct Vec_00136B80 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00136B80() {}
    Vec_00136B80(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Rgba_00136B80 {
    struct Bytes { unsigned char r, g, b, a; } v;
    Rgba_00136B80(unsigned char r, int g, int b, int a)
    {
        v.r = r;
        v.g = g;
        v.b = b;
        v.a = a;
    }
};

struct Obj_00136B80 {
    char pad[0x50];
    Vec_00136B80 m_pos;
};

extern int D_0038FC78;
extern "C" int func_001E7DE8(void* params, unsigned int key, int* out, int required);
extern "C" int func_001E7EB0(void* params, unsigned int key, float* out, int required);
extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);
extern "C" Obj_00136B80* func_0022DD38(int a);
extern "C" void func_001235E8(Vec_00136B80* a, Vec_00136B80* b, unsigned int c0, unsigned int c1, int a4);

extern "C" int func_00136B80(void* params)
{
    float heading;
    float pitch;
    int r;
    int g;
    int b;
    func_001E7EB0(params, 0xFD4BC03E, &heading, 1);
    float len = 50.0f;
    func_001E7EB0(params, 0xD8604126, &pitch, 1);
    pitch = -pitch * 0.01745329425f;
    heading = (90.0f - heading) * 0.01745329425f;
    func_001E7DE8(params, 0x93F60062, &r, 1);
    func_001E7DE8(params, 0xFE2BE489, &g, 1);
    func_001E7DE8(params, 0x8E411006, &b, 1);
    Rgba_00136B80 col(r, g, b, 0x80);
    Vec_00136B80 pos = func_0022DD38(D_0038FC78)->m_pos;
    float px = pos.x;
    float py = pos.y + 75.0f;
    float pz = pos.z;
    float ey = func_00341068(pitch) * len + py;
    float h = func_00340F60(pitch) * len;
    float ex = func_00340F60(heading) * h + px;
    float ez = func_00341068(heading) * h + pz;
    unsigned int c = 0xFF000000 | (col.v.b << 16) | (col.v.g << 8) | col.v.r;
    Vec_00136B80 start(px, py, pz, 0.0f);
    Vec_00136B80 end(ex, ey, ez, 0.0f);
    func_001235E8(&start, &end, c, c, 1);
    return 1;
}
