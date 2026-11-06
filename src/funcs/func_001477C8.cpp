// Fetches the 2x2 block of pixels at (x, y), clamped at the right and bottom edges.
struct Rgba_001477C8 {
    unsigned char r, g, b, a;
};

extern "C" void func_001477C8(Rgba_001477C8* out, Rgba_001477C8* img, unsigned short x, unsigned short y, unsigned short w, unsigned short h)
{
    int dx = x < w - 1;
    int edge = y >= h - 1;
    Rgba_001477C8* p = &img[y * w + x];
    out[0] = p[0];
    out[1] = p[dx];
    if (!edge)
        p += w;
    out[2] = p[0];
    out[3] = p[dx];
}
