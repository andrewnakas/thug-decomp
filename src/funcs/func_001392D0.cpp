struct Heap_001392D0 {
    char pad[0xD8];
    void* mD8;
};

extern "C" void func_0010A950(Heap_001392D0* heap, void* sub);
extern "C" void func_0010A9B0(Heap_001392D0* heap);
extern Heap_001392D0* D_00388A70;

struct Node_001392D0;
extern "C" void* func_001391B0(Node_001392D0* self, int id);
extern "C" void* func_00138F58(Node_001392D0* self, int name, int a, int b, int c);
extern "C" int func_00138738(void* p, void* c);
extern "C" bool func_001390E0(Node_001392D0* self, void* c);

extern "C" int func_001392D0(Node_001392D0* self, int id, int name)
{
    void* p = func_001391B0(self, id);
    if (p) {
        func_0010A950(D_00388A70, D_00388A70->mD8);
        void* c = func_00138F58(self, name, 0, 0, 1);
        int r = func_00138738(p, c);
        func_001390E0(self, c);
        func_0010A9B0(D_00388A70);
        return r;
    }
    return 0;
}
