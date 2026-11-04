struct File_001103E8 {
    int fd;
    int pos;
    int size;
    char pad[0xC80C - 0xC];
    int bufPos;
    char pad2[0xC820 - 0xC810];
    char name[256];
};

extern char D_00388E30[];
extern int D_00388E20;

extern "C" void func_0010FE68();
extern "C" File_001103E8* func_0010FC90();
extern "C" int func_0010FD88(const char* mode);
extern "C" void func_0010FD30(File_001103E8* f);
extern "C" char* func_003317AC(const char* s, int c);
extern "C" char* func_00332088(char* dst, const char* src, int n);
extern "C" int func_0031E880(const char* path, int mode);
extern "C" int func_0031EC88(int fd, int offset, int whence);
extern "C" int func_0031EB08(int fd);

extern "C" File_001103E8* func_001103E8(const char* name, const char* mode)
{
    func_0010FE68();
    File_001103E8* f = func_0010FC90();
    if (f == 0) {
        return 0;
    }
    int flags = func_0010FD88(mode);
    if (flags == 0) {
        return 0;
    }
    char path[256];
    if (func_003317AC(name, ':')) {
        func_00332088(path, name, 255);
    } else {
        *(int*)path = *(int*)D_00388E30;
        *(unsigned short*)(path + 4) = *(unsigned short*)(D_00388E30 + 4);
        func_00332088(path + 5, name, 250);
    }
    path[255] = 0;
    for (char* p = path; *p; p++) {
        if (*p == '\\') {
            *p = '/';
        }
    }
    f->fd = func_0031E880(path, flags);
    if (f->fd >= 0) {
        f->size = f->pos = func_0031EC88(f->fd, 0, 2);
        if (f->size >= 0) {
            if ((flags & 0x600) == 0x200) {
                goto ok;
            }
            f->pos = func_0031EC88(f->fd, 0, 0);
            if (f->pos >= 0) {
                goto ok;
            }
        }
        func_0031EB08(f->fd);
    }
    func_0010FD30(f);
    return 0;
ok:
    f->bufPos = 0xC800;
    func_00332088(f->name, name, 255);
    D_00388E20++;
    return f;
}
