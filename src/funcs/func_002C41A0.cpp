struct Box_002C41A0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Arr_002C41A0 {
    int m0;
    int m4;
    int m8;
    unsigned int mC;
};

extern char D_0037A650[];
extern "C" Arr_002C41A0* func_001E55F8(char* name, int v);
extern "C" void* func_001E93A0(void* p, int i);
extern "C" int func_001E9270(void* p, int i);
extern "C" char* func_002BAA48(Box_002C41A0* b, int idx);
extern "C" void func_002BAA50(Box_002C41A0* b);

struct Park_002C41A0 {
    char pad[0x6AA8];
    Box_002C41A0 m6AA8[8];
    unsigned int m6AD8;
    void LoadSizes();
};

void Park_002C41A0::LoadSizes()
{
    Arr_002C41A0* a = func_001E55F8(D_0037A650, 1);
    m6AD8 = a->mC;
    for (unsigned int i = 4; i < m6AD8 + 4; i++) {
        void* e = func_001E93A0(a, i);
        *func_002BAA48(&m6AA8[i], 0) = func_001E9270(e, 0);
        *func_002BAA48(&m6AA8[i], 2) = func_001E9270(e, 1);
        *func_002BAA48(&m6AA8[i], 3) = func_001E9270(e, 2);
        *func_002BAA48(&m6AA8[i], 5) = func_001E9270(e, 3);
        *func_002BAA48(&m6AA8[i], 1) = 0;
        func_002BAA50(&m6AA8[i]);
    }
    m6AD8 += 4;
}
