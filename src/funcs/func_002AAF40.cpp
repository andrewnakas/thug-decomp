struct S_002AAF40 {
    char pad[0x16C];
    int m16C;
};

extern S_002AAF40* D_00392068;
extern char D_00378B88[];
extern char D_00392200[];
extern char D_00392208[];
extern char D_00378BA0[];
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" int func_001E5648(char* s, int v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

bool func_002AAF40()
{
    S_002AAF40* s = D_00392068;
    for (int i = 0; i < 7; i++) {
        void* p = func_001E6978(func_001190D0(8));
        func_001E7268(p, D_00392200, func_001E5648(D_00378B88, 1) + i);
        int mask = 1 << i;
        if (s->m16C & mask) {
            func_001F0370(D_00392208, p, 0, 0);
        } else {
            func_001F0370(D_00378BA0, p, 0, 0);
        }
        if (p) {
            func_001E6AE8(p, 3);
        }
    }
    return true;
}
