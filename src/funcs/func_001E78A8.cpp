struct Comp_001E78A8 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    unsigned int m4;
    void* m8;
};

struct Struct_001E78A8;

extern "C" void* func_001E8CD0(unsigned int);
extern "C" Comp_001E78A8* func_001E4ED8(void*);
extern "C" void func_001E6F90(Struct_001E78A8*, Comp_001E78A8*);

extern "C" void func_001E78A8(Struct_001E78A8* s, unsigned int name, void* v)
{
    Comp_001E78A8* c = func_001E4ED8(func_001E8CD0(16));
    c->m4 = name;
    c->m1 = 10;
    c->m8 = v;
    func_001E6F90(s, c);
}
