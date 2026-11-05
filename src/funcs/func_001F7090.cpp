extern "C" void* func_00331404(void* dst, const void* src, int size);

int func_001F7090(char* dst1, int size1, char* dst2, int size2, const char* src1, int len1, const char* src2, int len2)
{
    if (size1 + size2 < len1 + len2) {
        return 0;
    }
    if (len1 >= size1) {
        func_00331404(dst1, src1, size1);
        func_00331404(dst2, src1 + size1, len1 - size1);
        func_00331404(dst2 + len1 - size1, src2, len2);
    } else {
        int room = size1 - len1;
        if (len2 >= room) {
            func_00331404(dst1, src1, len1);
            func_00331404(dst1 + len1, src2, room);
            func_00331404(dst2, src2 + size1 - len1, len2 - room);
        } else {
            func_00331404(dst1, src1, len1);
            func_00331404(dst1 + len1, src2, len2);
        }
    }
    return len1 + len2;
}
