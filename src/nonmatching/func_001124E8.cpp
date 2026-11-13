/* fuzzy: 88.8 */
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_001F0D78(const char* s);

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
    char* p = path + func_00331BB8(path);
    while (*--p != '\\') {
    }
    func_00331A9C(file, p + 1);
    *p = 0;
    if (path[0] == '\\') {
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
