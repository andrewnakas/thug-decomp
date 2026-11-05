extern "C" char* func_001E91C0(void* arr, int idx);
extern "C" char* func_003331D0(char* dst, const char* src);
extern "C" int func_00331BB8(const char* s);

static inline bool IsDigit_00247AF8(unsigned char c)
{
    return c >= '0' && c <= '9';
}

void func_00247AF8(char* src, char* dst, void* kArr, void* tArr)
{
    while (*src) {
        if (src[0] == '\\' && src[1] == 't' && IsDigit_00247AF8(src[2])) {
            int n = src[2] - '0';
            if (IsDigit_00247AF8(src[3])) {
                n *= 10;
                n += src[3] - '0';
                src++;
            }
            char* s = func_001E91C0(tArr, n - 1);
            func_003331D0(dst, s);
            int len = func_00331BB8(s);
            for (int i = 0; i < len; i++)
                dst++;
            src++;
            src += 2;
        } else if (src[0] == '\\' && src[1] == 'k' && IsDigit_00247AF8(src[2])) {
            int n = src[2] - '0';
            if (IsDigit_00247AF8(src[3])) {
                n *= 10;
                n += src[3] - '0';
                src++;
            }
            char* s = func_001E91C0(kArr, n - 1);
            func_003331D0(dst, s);
            int len = func_00331BB8(s);
            for (int i = 0; i < len; i++)
                dst++;
            src++;
            src += 2;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = 0;
}
