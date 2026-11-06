struct File_001100C0 {
    int m0;
    int pos;
    int size;
    char buf[0xC800];
    unsigned int bufpos;
    int m10;
    int m14;
    int base;
};

extern int D_00388E28;

static inline unsigned int Min_001100C0(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}
extern "C" void func_0010FE68();
extern "C" void* func_00331404(void* dst, const void* src, unsigned int n);
extern "C" int func_0031EC88(int fd, int off, int whence);
extern "C" int func_0031EEC0(int fd, void* buf, unsigned int n);

extern "C" unsigned int func_001100C0(char* dst, unsigned int size, unsigned int count, File_001100C0* f)
{
    int n = size * count;
    func_0010FE68();
    unsigned int done = 0;
    if (f->size < f->pos + n) n = f->size - f->pos;
    if (f->bufpos < 0xC800 && n > 0) {
        unsigned int avail = 0xC800 - f->bufpos;
        done = Min_001100C0(n, avail);
        func_00331404(dst, &f->buf[f->bufpos], done);
        dst += done;
        f->bufpos += done;
        f->pos += done;
    }
    if (n != done) {
        unsigned int rem = n - done;
        if (rem >= 0xC800) {
            func_0031EC88(D_00388E28, f->base + f->pos, 0);
            int r = func_0031EEC0(D_00388E28, dst, rem);
            if (r < 0) r = 0;
            rem = r;
        } else {
            func_0031EC88(D_00388E28, f->base + f->pos, 0);
            func_0031EEC0(D_00388E28, f->buf, 0xC800);
            func_00331404(dst, f->buf, rem);
            f->bufpos = rem;
        }
        f->pos += rem;
        done += rem;
    }
    return done / size;
}
