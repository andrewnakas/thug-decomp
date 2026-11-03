struct Comp_001E9B08 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    union {
        int i;
        float f;
        void* p;
    } m8;
};

struct Struct_001E9B08;

extern "C" Comp_001E9B08* func_001E6E90(Struct_001E9B08*, Comp_001E9B08*);
extern "C" unsigned int func_001E9508(unsigned int, int, unsigned char*, unsigned int);
extern "C" unsigned int func_001E9688(unsigned int, unsigned char*, unsigned int, float);
extern "C" unsigned int func_001E9730(unsigned int, unsigned int, unsigned char*, unsigned int);
extern "C" unsigned int func_001E9790(unsigned int, void*, unsigned char*, unsigned int);
extern "C" unsigned int func_001E9850(unsigned int, void*, unsigned char*, unsigned int);
extern "C" unsigned int func_001E9910(unsigned int, void*, unsigned char*, unsigned int);
extern "C" unsigned int func_001E9980(unsigned int, void*, unsigned char*, unsigned int);
extern "C" unsigned int func_001E99F8(unsigned int, void*, unsigned char*, unsigned int, int);
extern "C" unsigned int func_001E9A80(unsigned int, void*, unsigned char*, unsigned int, int);

extern "C" unsigned int func_001E9B08(Struct_001E9B08* s, unsigned char* buf, unsigned int size, int flags)
{
    unsigned int left = size;
    Comp_001E9B08* c = 0;
    if (s)
        c = func_001E6E90(s, 0);
    while (c) {
        unsigned int w = 0;
        switch (c->m1) {
        case 1:
            w = func_001E9508(c->m4, c->m8.i, buf, left);
            break;
        case 2:
            w = func_001E9688(c->m4, buf, left, c->m8.f);
            break;
        case 13:
            w = func_001E9730(c->m4, c->m8.i, buf, left);
            break;
        case 3:
            w = func_001E9790(c->m4, c->m8.p, buf, left);
            break;
        case 4:
            w = func_001E9850(c->m4, c->m8.p, buf, left);
            break;
        case 5:
            w = func_001E9910(c->m4, c->m8.p, buf, left);
            break;
        case 6:
            w = func_001E9980(c->m4, c->m8.p, buf, left);
            break;
        case 10:
            w = func_001E99F8(c->m4, c->m8.p, buf, left, flags);
            break;
        case 12:
            w = func_001E9A80(c->m4, c->m8.p, buf, left, flags);
            break;
        case 7:
            w = func_001E9730(c->m4, 0xB9C4F664, buf, left);
            break;
        }
        if (!w)
            return 0;
        left -= w;
        buf += w;
        c = func_001E6E90(s, c);
    }
    if (!left)
        return 0;
    left--;
    *buf = 0;
    return size - left;
}
