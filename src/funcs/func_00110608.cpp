struct File_00110608 {
    int fd;
    int pos;
    int size;
    char buffer[0xC800];
    unsigned int bufPos;
};

extern "C" void func_0010FE68();
extern "C" void* func_00331404(void* dst, const void* src, int n);
extern "C" int func_0031EEC0(int fd, void* buf, int n);

static inline unsigned int Min(unsigned int a, unsigned int b) { return a < b ? a : b; }
extern "C" unsigned int func_00110608(char* buf, unsigned int size, unsigned int count, File_00110608* f)
{
    unsigned int total = size * count;
    unsigned int done = 0;
    func_0010FE68();
    if (f->size < (int)(f->pos + total)) {
        total = f->size - f->pos;
    }
    if (f->bufPos < 0xC800 && (int)total > 0) {
        done = Min(total, 0xC800 - f->bufPos);
        func_00331404(buf, f->buffer + f->bufPos, done);
        buf += done;
        f->bufPos += done;
        f->pos += done;
    }
    if (total != done) {
        unsigned int rem = total - done;
        if (rem > 0xC7FF) {
            int r = func_0031EEC0(f->fd, buf, rem);
            if (r < 0) {
                r = 0;
            }
            rem = r;
        } else {
            func_0031EEC0(f->fd, f->buffer, 0xC800);
            func_00331404(buf, f->buffer, rem);
            f->bufPos = rem;
        }
        f->pos += rem;
        done += rem;
    }
    return done / size;
}
