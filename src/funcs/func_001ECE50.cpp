struct Heap_001ECE50 {
    char pad[0xEC];
    int mEC;
};
extern Heap_001ECE50* D_00388A70;

struct Vec_001ECE50 {
    int m0;
    float x;
    float y;
    float z;
};

struct Comp_001ECE50 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    int m4;
    union {
        int i;
        float f;
        void* p;
        Vec_001ECE50* v;
    } m8;
};

struct Struct_001ECE50;
struct Array_001ECE50;

extern "C" void func_0010A950(void*, int);
extern "C" void func_0010A9B0(void*);
extern "C" void* func_0010BDE0(unsigned int);
extern "C" int func_001EC7A0(unsigned char*);
extern "C" void* func_001E4DE0(unsigned char*);
extern "C" void* func_001E8C80(unsigned int);
extern "C" Vec_001ECE50* func_001E4C68(void*);
extern "C" void* func_001E8C30(unsigned int);
extern "C" Vec_001ECE50* func_001E4C80(void*);
extern "C" void* func_001190D0(unsigned int);
extern "C" Struct_001ECE50* func_001E6978(void*);
extern "C" unsigned char* func_001EC088(Struct_001ECE50*, unsigned char*, Struct_001ECE50*);
extern "C" void* func_00122CF8(unsigned int);
extern "C" Array_001ECE50* func_001E8DD0(void*);
extern "C" unsigned char* func_001EB450(Array_001ECE50*, unsigned char*, Struct_001ECE50*);
extern "C" unsigned char* func_001EB180(unsigned char*, Comp_001ECE50*, int);
extern "C" unsigned char* func_001ECD40(unsigned char*);
extern "C" Comp_001ECE50* func_001E6DD0(Struct_001ECE50*, int);
extern "C" void func_001E6360(Comp_001ECE50*, Comp_001ECE50*);
extern "C" Struct_001ECE50* func_001E6A00(Struct_001ECE50*, Struct_001ECE50*);

static inline float ReadFloat_001ECE50(unsigned char* p)
{
    union {
        int i;
        float f;
    } u;
    u.i = func_001EC7A0(p);
    return u.f;
}

extern "C" unsigned char* func_001ECE50(unsigned char* p, Struct_001ECE50* params, Comp_001ECE50* c)
{
    int flag = 0;
    switch (*p++) {
    case 0x17:
        c->m1 = 1;
        c->m8.i = func_001EC7A0(p);
        p += 4;
        break;
    case 0x1A:
        c->m1 = 2;
        c->m8.f = ReadFloat_001ECE50(p);
        p += 4;
        break;
    case 0x16:
        c->m1 = 13;
        c->m8.i = func_001EC7A0(p);
        p += 4;
        break;
    case 0x1B: {
        c->m1 = 3;
        int len = func_001EC7A0(p);
        p += 4;
        c->m8.p = func_001E4DE0(p);
        p += len;
        break;
    }
    case 0x1C: {
        c->m1 = 4;
        int len = func_001EC7A0(p);
        p += 4;
        c->m8.p = func_001E4DE0(p);
        p += len;
        break;
    }
    case 0x1E: {
        c->m1 = 6;
        float x = ReadFloat_001ECE50(p);
        p += 4;
        float y = ReadFloat_001ECE50(p);
        p += 4;
        float z = ReadFloat_001ECE50(p);
        p += 4;
        c->m8.v = func_001E4C68(func_001E8C80(16));
        c->m8.v->x = x;
        c->m8.v->y = y;
        c->m8.v->z = z;
        break;
    }
    case 0x1F: {
        c->m1 = 5;
        float x = ReadFloat_001ECE50(p);
        p += 4;
        float y = ReadFloat_001ECE50(p);
        p += 4;
        c->m8.v = func_001E4C80(func_001E8C30(12));
        c->m8.v->x = x;
        c->m8.v->y = y;
        break;
    }
    case 3: {
        p--;
        Struct_001ECE50* s = func_001E6978(func_001190D0(8));
        p = func_001EC088(s, p, params);
        c->m1 = 10;
        c->m8.p = s;
        break;
    }
    case 5: {
        p--;
        func_0010A950(D_00388A70, D_00388A70->mEC);
        Array_001ECE50* a = func_001E8DD0(func_00122CF8(16));
        func_0010A9B0(D_00388A70);
        p = func_001EB450(a, p, params);
        c->m1 = 12;
        c->m8.p = a;
        break;
    }
    case 0x38:
        flag = 1;
    case 0x30:
        p = func_001EB180(p, c, flag);
        break;
    case 0x23: {
        p++;
        c->m4 = func_001EC7A0(p);
        p += 4;
        unsigned char* start = p;
        p = func_001ECD40(p);
        c->m1 = 7;
        unsigned int len = p - start;
        func_0010A950(D_00388A70, D_00388A70->mEC);
        unsigned char* buf = (unsigned char*)func_0010BDE0(len);
        func_0010A9B0(D_00388A70);
        unsigned char* d = buf;
        for (unsigned int i = 0; i < len; i++)
            *d++ = *start++;
        c->m8.p = buf;
        break;
    }
    case 0x2D: {
        p++;
        int name = func_001EC7A0(p);
        p += 4;
        if (params) {
            Comp_001ECE50* f = func_001E6DD0(params, name);
            if (f)
                func_001E6360(c, f);
        }
        break;
    }
    case 0x2C:
        if (params) {
            Struct_001ECE50* s = func_001E6978(func_001190D0(8));
            func_001E6A00(s, params);
            c->m8.p = s;
            c->m1 = 10;
        }
        break;
    case 4:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 24:
    case 25:
    case 29:
    case 32:
    case 33:
    case 34:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 46:
    case 47:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
        break;
    }
    return p;
}
