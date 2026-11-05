extern "C" void* func_00263320(void* map, int* key, int* out);
extern "C" int func_002623B8(void* p);
extern "C" void func_00261BC0(void* p, int a);

struct Map_00262C78 {
    int m0;
};

struct Obj_00262C78 {
    int m0;
    Map_00262C78 m4;
    unsigned int m8;
    void Run(int a);
};

void Obj_00262C78::Run(int a)
{
    unsigned int n = m8;
    for (unsigned int i = 0; i < n; i++) {
        int key = i;
        int out;
        void* p = func_00263320(&m4, &key, &out);
        if (!func_002623B8(p))
            func_00261BC0(p, a);
    }
}
