struct Sk_002ACC98 {
    char pad[0x88];
    void* m88;
};

extern char* D_0038C308;
extern "C" void func_002AB2E8(Sk_002ACC98* s, int v);
extern "C" int func_00201288(void* p);
extern "C" void func_00105260(void* p, void* q);

struct Obj_002ACC98 {
    char pad[0x10];
    void* m10;
    char pad14[0x1C - 0x14];
    Sk_002ACC98* m1C;
    int Run();
};

int Obj_002ACC98::Run()
{
    Sk_002ACC98* s = m1C;
    char* g = D_0038C308;
    func_002AB2E8(s, 1);
    if (!func_00201288(m10))
        func_00105260(g + 8, s->m88);
    return 1;
}
