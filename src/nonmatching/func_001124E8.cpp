/* fuzzy: 90.8 */
/* blocked: game loop test compares the char with 0x5C in a register and is not duplicated; an inline test keeps the bottom test but gives xori, a plain test is duplicated (size +8..+0x18). */
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_001F0D78(const char* s);

static inline int IsSep_001124E8(int c)
{
    return c == '\\';
}

extern "C" void func_001124E8(const char* name, int* dirCrc, int* fileCrc)
{
    char path[0x80];
    char dir[0x80];
    char file[0x80];
    unsigned int i;
    for (i = 0; i <= (unsigned int)func_00331BB8(name); i++) {
        path[i] = name[i];
        if (path[i] == '/') {
            path[i] = '\\';
        }
    }
    int len = func_00331BB8(path);
    char* p = &path[len - 1];
    char* fn = &path[len];
    char c;
    while (!IsSep_001124E8(c = *p)) {
        p--;
        fn--;
    }
    func_00331A9C(file, fn);
    *p = 0;
    /* c == '\\' here; the game compares with the loaded char: `bne $v0,$s1` at 0x1125AC, $s1 from
       `lb $s1,0($s0)` in the loop at 0x112584. */
    if (path[0] == c) {
        func_00331A9C(dir, &path[1]);
    } else {
        func_00331A9C(dir, path);
    }
    if (dirCrc) {
        *dirCrc = func_001F0D78(dir);
    }
    if (fileCrc) {
        *fileCrc = func_001F0D78(file);
    }
}
