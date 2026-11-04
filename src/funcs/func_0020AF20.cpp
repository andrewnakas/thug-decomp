extern char* D_00394144;
extern char D_003F5780[];
extern "C" int func_00331BB8(const char* s);
extern "C" void func_0020AED8();

void func_0020AF20(const char* s)
{
    int len = func_00331BB8(s);
    if ((int)D_003F5780 < (int)(D_00394144 + len)) func_0020AED8();
    for (int i = 0; i < len; i++) {
        if (*s != '\n') {
            *D_00394144++ = *s++;
        } else {
            s++;
            *D_00394144++ = '\r';
            *D_00394144++ = '\n';
        }
    }
}
