struct Obj_00236D50 {
    void Escape(char* dst, char* src);
};

void Obj_00236D50::Escape(char* dst, char* src)
{
    while (*src) {
        if (*src == ' ') {
            *dst++ = '\\';
            *dst++ = '_';
        } else {
            *dst++ = *src;
        }
        src++;
    }
    *dst = 0;
}
