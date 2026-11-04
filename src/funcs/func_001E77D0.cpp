struct Comp_001E77D0 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    void* m8;
};

struct Struct_001E77D0;

extern "C" void* func_001E8CD0(unsigned int);
extern "C" Comp_001E77D0* func_001E4ED8(void*);
extern "C" void func_001E6F90(Struct_001E77D0*, Comp_001E77D0*);
extern "C" void* func_001190D0(unsigned int);
extern "C" Struct_001E77D0* func_001E6978(void*);
extern "C" void func_001E6A00(Struct_001E77D0*, Struct_001E77D0*);

extern "C" void func_001E77D0(Struct_001E77D0* s, unsigned int name, Struct_001E77D0* src)
{
    Comp_001E77D0* c = func_001E4ED8(func_001E8CD0(16));
    c->m4 = name;
    c->m1 = 10;
    Struct_001E77D0* n = func_001E6978(func_001190D0(8));
    c->m8 = n;
    func_001E6A00(n, src);
    func_001E6F90(s, c);
}
