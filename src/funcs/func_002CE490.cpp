struct A_002CE490 {
    char pad[0x18];
    A_002CE490* m18;
};

struct B_002CE490 {
    int m0;
    B_002CE490* m4;
};

extern "C" void func_002CC920(A_002CE490* a);
extern "C" void func_002997F0(B_002CE490* b);
extern "C" void func_002997B0(B_002CE490* b);

struct Obj_002CE490 {
    char pad[0xC];
    A_002CE490* mC;
    B_002CE490* m10;
    void Update();
};

void Obj_002CE490::Update()
{
    for (A_002CE490* a = mC; a; a = a->m18)
        func_002CC920(a);
    for (B_002CE490* b = m10; b; b = b->m4) {
        func_002997F0(b);
        func_002997B0(b);
    }
}
