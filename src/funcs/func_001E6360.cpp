struct Heap_001E6360 {
    char m_pad[0xEC];
    int m_EC;
};

struct Vec3_001E6360 {
    int m_0;
    float x;
    float y;
    float z;
};

struct Vec2_001E6360 {
    int m_0;
    float x;
    float y;
};

struct Comp_001E6360 {
    char m_0;
    unsigned char m_type;
    unsigned short m_size;
    int m_name;
    union {
        int i;
        void* p;
        char* s;
        unsigned char* b;
        Vec3_001E6360* v3;
        Vec2_001E6360* v2;
    };
};

extern Heap_001E6360* D_00388A70;
extern "C" void func_001E6250(Comp_001E6360* c);
extern "C" char* func_001E4DE0(char* s);
extern "C" void* func_001E8C30(int size);
extern "C" Vec2_001E6360* func_001E4C80(void* mem);
extern "C" void* func_001E8C80(int size);
extern "C" Vec3_001E6360* func_001E4C68(void* mem);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6A00(void* d, void* s);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* mem);
extern "C" void func_001E66C0(void* d, void* s);
extern "C" void func_0010A950(void* heap, int a);
extern "C" void func_0010A9B0(void* heap);
extern "C" unsigned char* func_0010BDE0(unsigned int size);

extern "C" void func_001E6360(Comp_001E6360* d, Comp_001E6360* s)
{
    if (d->p) {
        func_001E6250(d);
    }
    d->m_type = s->m_type;
    d->m_name = s->m_name;
    switch (s->m_type) {
    case 0:
        break;
    case 1:
    case 2:
    case 13:
        d->i = s->i;
        break;
    case 3:
    case 4:
        d->s = func_001E4DE0(s->s);
        break;
    case 5:
        d->v2 = func_001E4C80(func_001E8C30(0xC));
        d->v2->x = s->v2->x;
        d->v2->y = s->v2->y;
        break;
    case 6:
        d->v3 = func_001E4C68(func_001E8C80(0x10));
        d->v3->x = s->v3->x;
        d->v3->y = s->v3->y;
        d->v3->z = s->v3->z;
        break;
    case 10:
        d->p = func_001E6978(func_001190D0(8));
        func_001E6A00(d->p, s->p);
        break;
    case 12:
        d->p = func_001E8DD0(func_00122CF8(0x10));
        func_001E66C0(d->p, s->p);
        break;
    case 7: {
        func_0010A950(D_00388A70, D_00388A70->m_EC);
        d->b = func_0010BDE0(s->m_size);
        d->m_size = s->m_size;
        func_0010A9B0(D_00388A70);
        unsigned char* dst = d->b;
        unsigned char* src = s->b;
        for (unsigned int i = 0; i < s->m_size; i++) {
            *dst++ = *src++;
        }
        break;
    }
    }
}
