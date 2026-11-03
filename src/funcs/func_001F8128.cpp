extern "C" void func_001F8270(char*, char*, int);

int func_001F8128(char* dst0, int sz0, char* dst1, int sz1, char* src0, int len0, char* src1, int len1)
{
    if (sz0 + sz1 < len0 + len1) {
        int over = len0 + len1 - (sz0 + sz1);
        if (over >= len1) {
            len0 -= over - len1;
            len1 = 0;
        } else {
            len1 -= over;
        }
    }
    int rem = sz0 - len0;
    if (len0 >= sz0) {
        func_001F8270(dst0, src0, sz0);
        func_001F8270(dst1, src0 + sz0, len0 - sz0);
        func_001F8270(dst1 + len0 - sz0, src1, len1);
    } else if (len1 >= rem) {
        func_001F8270(dst0, src0, len0);
        func_001F8270(dst0 + len0, src1, rem);
        func_001F8270(dst1, src1 + sz0 - len0, len1 - rem);
    } else {
        func_001F8270(dst0, src0, len0);
        func_001F8270(dst0 + len0, src1, len1);
    }
    return len0 + len1;
}
