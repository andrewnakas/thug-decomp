struct Heap_001E7958 {
    char pad[0xEC];
    int mEC;
};
extern Heap_001E7958* D_00388A70;

struct Comp_001E7958 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    void* m8;
};

struct Struct_001E7958;

extern "C" void func_0010A950(void*, int);
extern "C" void func_0010A9B0(void*);
extern "C" void* func_0010BDE0(unsigned int);
extern "C" void* func_001E8CD0(unsigned int);
extern "C" Comp_001E7958* func_001E4ED8(void*);
extern "C" void func_001E6F90(Struct_001E7958*, Comp_001E7958*);

extern "C" void func_001E7958(Struct_001E7958* s, unsigned int name, unsigned char* data, unsigned int size)
{
    Comp_001E7958* c = func_001E4ED8(func_001E8CD0(16));
    c->m4 = name;
    c->m1 = 7;
    c->m2 = size;
    func_0010A950(D_00388A70, D_00388A70->mEC);
    unsigned char* buf = (unsigned char*)func_0010BDE0(size);
    func_0010A9B0(D_00388A70);
    unsigned char* d = buf;
    for (unsigned int i = 0; i < size; i++)
        *d++ = *data++;
    c->m8 = buf;
    func_001E6F90(s, c);
}
