extern int* D_0038A0E4;
extern void* D_004653C0[];

extern "C" int func_0013AFA8(void* obj)
{
    int count = 0;
    for (unsigned int i = 0; i < 10; i++) {
        int idx = D_0038A0E4[i];
        if (idx >= 0) {
            if (D_004653C0[idx] == obj) {
                return count;
            }
            count++;
        }
    }
    return -1;
}
