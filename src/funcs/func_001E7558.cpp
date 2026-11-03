struct Pair_001E7558 {
    int m0;
    float x;
    float y;
};

struct Comp_001E7558 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    Pair_001E7558* m8;
};

struct Struct_001E7558;

extern "C" void* func_001E8CD0(unsigned int);
extern "C" Comp_001E7558* func_001E4ED8(void*);
extern "C" void func_001E6F90(Struct_001E7558*, Comp_001E7558*);
extern "C" void* func_001E8C30(unsigned int);
extern "C" Pair_001E7558* func_001E4C80(void*);

extern "C" void func_001E7558(Struct_001E7558* s, unsigned int name, float x, float y)
{
    Comp_001E7558* c = func_001E4ED8(func_001E8CD0(16));
    c->m4 = name;
    c->m1 = 5;
    c->m8 = func_001E4C80(func_001E8C30(12));
    c->m8->x = x;
    c->m8->y = y;
    func_001E6F90(s, c);
}
