extern "C" void* func_00263320(void* map, unsigned int* key, int* out);
extern "C" int func_00261118(void* p, int a);

struct Map_002629E0 {
    int m0;
};

struct Obj_002629E0 {
    int m0;
    Map_002629E0 m4;
    unsigned int m8;
    void Run();
};

void Obj_002629E0::Run()
{
    unsigned int n = m8;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int key = i;
        int out;
        func_00261118(func_00263320(&m4, &key, &out), 0);
    }
}
