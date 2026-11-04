extern char D_00371C78[];

struct Iter_002A5928 {
    int m0;
    int m4;
    void* m8;
    Iter_002A5928() { m8 = D_00371C78; m4 = 0; }
    ~Iter_002A5928() { m8 = D_00371C78; }
};

extern "C" void* func_002A53F8(void* self, Iter_002A5928* it, int a);
extern "C" void* func_002A5490(void* self, Iter_002A5928* it, int a);
extern "C" int func_002B2280(void* e);

struct Table_002A5928 {
    int m0;
    int Count();
};

int Table_002A5928::Count()
{
    Iter_002A5928 it;
    int n = 0;
    for (void* e = func_002A53F8(this, &it, 0); e; e = func_002A5490(this, &it, 0)) {
        if (!func_002B2280(e))
            n++;
    }
    return n;
}
