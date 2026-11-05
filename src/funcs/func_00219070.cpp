struct Heap_00219070 {
    char pad[0xDC];
    void* mDC;
};

extern Heap_00219070* D_00388A70;

extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E8A30(void* params, unsigned int name, int* out, int req);
extern "C" void func_0010A950(Heap_00219070* heap, void* ctx);
extern "C" void* func_0010ACE0(Heap_00219070* heap, int id);

bool Cmd_00219070(void* params, void* script)
{
    int a = 0;
    int b;
    if (func_001E88D8(params, 0, &a, 0)) {
        if (a == 0)
            func_0010A950(D_00388A70, D_00388A70->mDC);
    } else {
        func_001E8A30(params, 0, &b, 1);
        func_0010A950(D_00388A70, func_0010ACE0(D_00388A70, b));
    }
    return true;
}
