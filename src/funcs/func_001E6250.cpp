struct Comp_001E6250 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    void* m8;
};

extern "C" void func_001E4E58(void*);
extern "C" void func_001E8AC0(void*);
extern "C" void func_001E8B70(void*);
extern "C" void func_001E6AE8(void*, int);
extern "C" void func_001E6518(void*);
extern "C" void func_001E8DE8(void*, int);
extern "C" void func_0010BEB8(void*);

extern "C" void func_001E6250(Comp_001E6250* c)
{
    switch (c->m1) {
    case 3:
    case 4:
        if (c->m8)
            func_001E4E58(c->m8);
        break;
    case 5:
        if (c->m8)
            func_001E8AC0(c->m8);
        break;
    case 6:
        if (c->m8)
            func_001E8B70(c->m8);
        break;
    case 10:
        if (c->m8)
            func_001E6AE8(c->m8, 3);
        break;
    case 12:
        if (c->m8) {
            func_001E6518(c->m8);
            if (c->m8)
                func_001E8DE8(c->m8, 3);
        }
        break;
    case 7:
        if (c->m8)
            func_0010BEB8(c->m8);
        c->m2 = 0;
        break;
    }
    c->m8 = 0;
    c->m1 = 0;
}
