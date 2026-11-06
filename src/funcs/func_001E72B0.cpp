struct Comp_001E72B0 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    float m8;
};

struct Struct_001E72B0;

extern "C" void* func_001E8CD0(unsigned int);
extern "C" Comp_001E72B0* func_001E4ED8(void*);
extern "C" void func_001E6F90(Struct_001E72B0*, Comp_001E72B0*);

extern "C" void func_001E72B0(Struct_001E72B0* s, unsigned int name, float v)
{
    Comp_001E72B0* c = func_001E4ED8(func_001E8CD0(16));
    c->m4 = name;
    c->m1 = 2;
    c->m8 = v;
    func_001E6F90(s, c);
}
