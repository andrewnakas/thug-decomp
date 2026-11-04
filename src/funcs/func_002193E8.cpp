struct Obj_002193E8 {
    char pad[0x8];
    int m8;
};

struct Node_002193E8 {
    char pad[0x34];
    Obj_002193E8* m34;
    char pad38[0xC];
    void* m44;
};

extern char* D_00388A70;
extern char D_0038F428[];
extern char D_00370F58[];
extern char D_00370F68[];
extern char D_00370F78[];

extern "C" void* func_001190D0(int);
extern "C" void* func_001E6978(void*);
extern "C" Node_002193E8* func_0010B088(char*);
extern "C" Node_002193E8* func_0010B0A8(char*, Node_002193E8*);
extern "C" void func_001E6B30(void*);
extern "C" int func_001F0D78(void*);
extern "C" void func_001E73C8(void*, char*, int);
extern "C" int func_0010C258(Obj_002193E8*);
extern "C" void func_001E7268(void*, char*, int);
extern "C" void func_001F0370(char*, void*, int, int);
extern "C" void func_001E6AE8(void*, int);

bool func_002193E8(void* params, void* script)
{
    char* heap = D_00388A70;
    void* s = func_001E6978(func_001190D0(8));
    for (Node_002193E8* n = func_0010B088(heap); n; n = func_0010B0A8(heap, n)) {
        Obj_002193E8* o = n->m34;
        func_001E6B30(s);
        func_001E73C8(s, D_0038F428, func_001F0D78(n->m44));
        func_001E7268(s, D_00370F58, func_0010C258(o));
        func_001E7268(s, D_00370F68, o->m8);
        func_001F0370(D_00370F78, s, 0, 0);
    }
    if (s)
        func_001E6AE8(s, 3);
    return true;
}
