extern unsigned long D_00388658;
extern unsigned long D_00388660;
extern unsigned long D_00388668;
extern int D_00393E98;
extern int D_00393E9C;
extern unsigned char* D_00393EA0;
extern char D_0035AA18[];
extern char D_0035AA30[];
extern char D_0035AA48[];

extern "C" void func_00105638();
extern "C" void func_00105710();
extern "C" void func_00105770(int r);
extern "C" void func_00105948(int p);
extern "C" void func_00103F28(const char* fmt, ...);

extern "C" int func_00105AF8(const char* src, unsigned char* dst, int count, int verbose)
{
    int i, c, len, r, s, last_match_length, code_buf_ptr;
    unsigned char code_buf[17], mask;

    D_00388658 = 0;
    D_00388660 = 0;
    D_00388668 = 0;
    func_00105638();
    code_buf[0] = 0;
    code_buf_ptr = mask = 1;
    s = 0;
    r = 4096 - 18;
    for (i = s; i < r; i++) {
        D_00393EA0[i] = ' ';
    }
    for (len = 0; len < 18 && count != 0; len++) {
        count--;
        c = *src++;
        D_00393EA0[r + len] = c;
    }
    if ((D_00388658 = len) == 0) {
        func_00105710();
        return 0;
    }
    for (i = 1; i <= 18; i++) {
        func_00105770(r - i);
    }
    func_00105770(r);
    do {
        if (D_00393E9C > len) {
            D_00393E9C = len;
        }
        if (D_00393E9C <= 2) {
            D_00393E9C = 1;
            code_buf[0] |= mask;
            code_buf[code_buf_ptr++] = D_00393EA0[r];
        } else {
            code_buf[code_buf_ptr++] = (unsigned char)D_00393E98;
            code_buf[code_buf_ptr++] = (unsigned char)(((D_00393E98 >> 4) & 0xF0) | (D_00393E9C - 3));
        }
        if ((mask <<= 1) == 0) {
            for (i = 0; i < code_buf_ptr; i++) {
                *dst++ = code_buf[i];
            }
            D_00388660 += code_buf_ptr;
            code_buf[0] = 0;
            code_buf_ptr = mask = 1;
        }
        last_match_length = D_00393E9C;
        for (i = 0; i < last_match_length && count != 0; i++) {
            c = *src++;
            count--;
            func_00105948(s);
            D_00393EA0[s] = c;
            if (s < 18 - 1) {
                D_00393EA0[s + 4096] = c;
            }
            s = (s + 1) & (4096 - 1);
            r = (r + 1) & (4096 - 1);
            func_00105770(r);
        }
        D_00388658 += i;
        while (i++ < last_match_length) {
            func_00105948(s);
            s = (s + 1) & (4096 - 1);
            r = (r + 1) & (4096 - 1);
            if (--len) {
                func_00105770(r);
            }
        }
    } while (len > 0);
    if (code_buf_ptr > 1) {
        for (i = 0; i < code_buf_ptr; i++) {
            *dst++ = code_buf[i];
        }
        D_00388660 += code_buf_ptr;
    }
    if (verbose) {
        func_00103F28(D_0035AA18, D_00388658);
        func_00103F28(D_0035AA30, D_00388660);
        func_00103F28(D_0035AA48, (double)D_00388660 / D_00388658);
    }
    func_00105710();
    return D_00388660;
}
