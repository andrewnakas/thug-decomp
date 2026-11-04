extern "C" void func_00105260(void* p, int v);
extern "C" void func_001048F0(int v);

struct Holder_002A7820 {
    int m0;
    int m4;
    int m8;
};

extern Holder_002A7820* D_0038C308;

struct Obj_002A7820 {
    char pad0[0x44];
    bool m44;
    bool m48;
    bool m4C;
    char pad50[0x7C - 0x50];
    int m7C;
    void ToggleM44();
};

void Obj_002A7820::ToggleM44() {
    Holder_002A7820* h = D_0038C308;
    m44 ^= true;
    if (m44) {
        func_00105260(&h->m8, m7C);
    } else {
        func_001048F0(m7C);
    }
}
