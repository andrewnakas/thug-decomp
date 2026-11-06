struct Rgba_001221B8 {
    struct Bytes { unsigned char r, g, b, a; } v;
    Rgba_001221B8(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        v.r = r;
        v.g = g;
        v.b = b;
        v.a = a;
    }
    Rgba_001221B8(const Rgba_001221B8& o) { v = o.v; }
};

struct Rect_001221B8 {
    int m[14];
};

extern Rect_001221B8 D_003BE8E8;

extern "C" int func_001387B0(void* o, int x, int y, int z, Rgba_001221B8 c);
extern "C" int func_00138920(void* o);
extern "C" int func_00138948(void* o);
extern "C" void func_00138830(void* o, unsigned short id, int axis, int v);
extern "C" int func_00138860(void* o, unsigned short id, int axis, int v, int z, Rgba_001221B8 c);

extern "C" int func_001221B8(void* o, const Rect_001221B8* in, int z, Rgba_001221B8 c)
{
    Rect_001221B8 r = *in;
    if (r.m[2] < r.m[0]) {
        int t = r.m[0];
        r.m[0] = r.m[2];
        r.m[2] = t;
    }
    if (r.m[1] > r.m[5]) {
        r.m[1] = r.m[5] - 1;
    }
    if (r.m[3] >= r.m[5]) {
        r.m[3] = r.m[5] - 2;
    }
    if (r.m[7] <= r.m[5]) {
        r.m[7] = r.m[5] + 2;
    }
    int gx = D_003BE8E8.m[4];
    int gy = D_003BE8E8.m[5];
    int dx = gx - r.m[4];
    int dy = gy - r.m[5];
    func_001387B0(o, dx, dy, 0, Rgba_001221B8(0x80, 0x80, 0x80, 0x80));
    float w = (float)(r.m[2] - r.m[4]);
    float d = (float)(r.m[4] - r.m[0]);
    float sx0 = (float)(r.m[4] + dx) / d;
    int my = ((r.m[1] + r.m[3]) >> 1) + dy;
    int gmy = (D_003BE8E8.m[1] + D_003BE8E8.m[3]) >> 1;
    int maxX = func_00138920(o);
    float sy0 = (float)(r.m[5] + dy) / (float)(r.m[5] + dy - my);
    float sx1 = (float)(maxX - (r.m[4] + dx)) / w;
    float h = (float)(r.m[7] - r.m[5]);
    int maxY = func_00138948(o);
    float sy1 = (float)(maxY - (r.m[5] + dy)) / h;

    int left = D_003BE8E8.m[0] - (r.m[0] + dx);
    left = (int)((float)left * sx0 + 0.5f);
    if (left < 0) {
        func_00138830(o, gx, 0, left);
    } else {
        func_00138860(o, gx, 0, left, z, c);
    }
    int right = D_003BE8E8.m[2] - (r.m[2] + dx);
    right = (int)((float)right * sx1 + 0.5f);
    if (right >= 0) {
        func_00138830(o, gx, 0, right);
    } else {
        func_00138860(o, gx, 0, right, z, c);
    }
    int top = gmy - my;
    top = (int)((float)top * sy0 + 0.5f);
    if (top < 0) {
        func_00138830(o, gy, 1, top);
    } else {
        func_00138860(o, gy, 1, top, z, c);
    }
    int bottom = D_003BE8E8.m[7] - (r.m[7] + dy);
    bottom = (int)((float)bottom * sy1 + 0.5f);
    if (bottom >= 0) {
        func_00138830(o, gy, 1, bottom);
    } else {
        func_00138860(o, gy, 1, bottom, z, c);
    }
    return 1;
}
