struct Array_001E93D8 {
    int m0;
    int m4;
    int m8;
    int mC;
};

extern "C" Array_001E93D8* func_001E55B8(unsigned int, int);
extern "C" unsigned int func_001E9300(Array_001E93D8*, int);
extern "C" unsigned char* func_001EC860(unsigned char*, unsigned short);
extern "C" unsigned char* func_001EC7F8(unsigned char*, unsigned int);

extern "C" unsigned char* func_001E93D8(unsigned char* p, unsigned char type, unsigned int name)
{
    Array_001E93D8* a = func_001E55B8(0x35115A20, 0);
    int n = a->mC;
    for (int i = 0; i < n; i++) {
        if (func_001E9300(a, i) == name) {
            *p++ = type | 0x80;
            *p = i;
            return p + 1;
        }
    }
    a = func_001E55B8(0x25231F42, 0);
    n = a->mC;
    for (int i = 0; i < n; i++) {
        if (func_001E9300(a, i) == name) {
            *p = type | 0x40;
            return func_001EC860(p + 1, i);
        }
    }
    *p = type;
    return func_001EC7F8(p + 1, name);
}
