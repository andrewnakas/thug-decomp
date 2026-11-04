struct Pool_002D92E8 {
    char pad[0x104];
    int m104;
};

extern Pool_002D92E8* D_00388A70;
extern char D_0037C7B8[];
extern "C" void func_0010A950(Pool_002D92E8* p, int v);
extern "C" void func_0010A9B0(Pool_002D92E8* p);
extern "C" void func_001F0370(char* s, void* a, int b, int c);

struct Obj_002D92E8 {
    int m0;
    int m4;
    void Start();
};

void Obj_002D92E8::Start()
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    m4 = 1;
    func_001F0370(D_0037C7B8, 0, 0, 0);
    func_0010A9B0(D_00388A70);
}
