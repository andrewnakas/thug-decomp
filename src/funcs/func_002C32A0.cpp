extern "C" void func_002CC458(void* p);
extern "C" void* func_002BC5A0(void* n);
extern "C" void* func_002BAB80(void* p);
extern "C" void func_002BE958(void* self, void* p, int f);
extern "C" void func_002B83B8(void* p, int v);
extern "C" void func_002BA848(void* p);

struct Node_002C32A0 {
    char pad0[0xC];
    Node_002C32A0* mC;
};

struct Obj_002C32A0 {
    void* m0;
    char pad4[0x7C];
    Node_002C32A0* m80;
    char pad84[0x6A7C];
    void* m6B00;
    void Rebuild(int v);
};

void Obj_002C32A0::Rebuild(int v) {
    func_002CC458(m6B00);
    Node_002C32A0* n = m80;
    while (n) {
        Node_002C32A0* next = n->mC;
        func_002BE958(this, func_002BAB80(func_002BC5A0(n)), 0);
        n = next;
    }
    func_002B83B8(m0, v);
    func_002BA848(m0);
}
