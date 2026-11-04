struct Rect_0014F2F8 {
    int m0;
    float x, y, w, h;
};

extern int D_0038882C;
extern "C" Rect_0014F2F8* func_0013AF50(void* p);
extern "C" void func_0017D468(int x0, int y0, int x1, int y1, unsigned int col);

static inline bool IsPal_0014F2F8() { return D_0038882C == 1; }

struct Obj_0014F2F8 {
    void* m0;
    char pad4[0xC - 4];
    unsigned char r, g, b, a;
    void Draw();
};

void Obj_0014F2F8::Draw()
{
    Rect_0014F2F8* rc = func_0013AF50(m0);
    int x = (IsPal_0014F2F8() ? 0x6C00 : 0x7000) + (int)(rc->x * (IsPal_0014F2F8() ? 10240.0f : 8192.0f));
    int y = (IsPal_0014F2F8() ? 0x7200 : 0x7000) + (int)(rc->y * (IsPal_0014F2F8() ? 7168.0f : 8192.0f));
    func_0017D468(x, y, x + (int)(rc->w * (IsPal_0014F2F8() ? 10240.0f : 8192.0f)),
                  y + (int)(rc->h * (IsPal_0014F2F8() ? 7168.0f : 8192.0f)),
                  r | (g << 8) | (b << 16) | (a << 24));
}
