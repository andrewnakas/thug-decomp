struct Comp_001E7648 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    void* m8;
};

struct Struct_001E7648;
struct Array_001E7648;

extern "C" void* func_001E8CD0(unsigned int);
extern "C" Comp_001E7648* func_001E4ED8(void*);
extern "C" void func_001E6F90(Struct_001E7648*, Comp_001E7648*);
extern "C" void* func_00122CF8(unsigned int);
extern "C" Array_001E7648* func_001E8DD0(void*);
extern "C" void func_001E66C0(Array_001E7648*, Array_001E7648*);

extern "C" void func_001E7648(Struct_001E7648* s, unsigned int name, Array_001E7648* src)
{
    Comp_001E7648* c = func_001E4ED8(func_001E8CD0(16));
    c->m4 = name;
    c->m1 = 12;
    Array_001E7648* a = func_001E8DD0(func_00122CF8(16));
    c->m8 = a;
    func_001E66C0(a, src);
    func_001E6F90(s, c);
}
