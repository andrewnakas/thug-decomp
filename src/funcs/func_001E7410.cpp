struct Vec_001E7410 {
    int m0;
    float x;
    float y;
    float z;
};

struct Comp_001E7410 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    Vec_001E7410* m8;
};

struct Struct_001E7410;

extern "C" void* func_001E8CD0(unsigned int);
extern "C" Comp_001E7410* func_001E4ED8(void*);
extern "C" void func_001E6F90(Struct_001E7410*, Comp_001E7410*);
extern "C" void* func_001E8C80(unsigned int);
extern "C" Vec_001E7410* func_001E4C68(void*);

extern "C" void func_001E7410(Struct_001E7410* s, unsigned int name, float x, float y, float z)
{
    Comp_001E7410* c = func_001E4ED8(func_001E8CD0(16));
    c->m4 = name;
    c->m1 = 6;
    c->m8 = func_001E4C68(func_001E8C80(16));
    c->m8->x = x;
    c->m8->y = y;
    c->m8->z = z;
    func_001E6F90(s, c);
}
