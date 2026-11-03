struct Node_0011F578 {
    unsigned char m0;
    unsigned char m1;
    char pad2[2];
    void* m4;
    void* m8;
};

extern "C" Node_0011F578* func_001E6E90(void* list, Node_0011F578* n);
extern "C" int func_001E8708(void* s, unsigned int id);
extern "C" void* func_00121C48(void* a, int t);
extern "C" void* func_00121E40(void* a, int u, int t);
extern "C" int func_001E8398(void* s, unsigned int id, int* out, int req);
extern "C" int func_001E7DE8(void* s, unsigned int id, int* out, int req);
extern "C" void func_001E6B30(void* s);
extern "C" int func_0011F548(void* a);
extern "C" void func_001E7360(void* s, unsigned int id, int v);

struct C_0011F578 {
    char pad[0x48];
    char m48[0xC];
    void Resolve();
};

void C_0011F578::Resolve()
{
    int t = 0;
    Node_0011F578* n = func_001E6E90(m48, 0);
    while (n) {
        Node_0011F578* next = func_001E6E90(m48, n);
        if (n->m1 == 10) {
            void* a = n->m4;
            if (func_001E8708(n->m8, 0xD81C03B0)) {
                a = func_00121C48(a, t);
                func_001E8398(a, 0x0D7260FD, &t, 0);
                func_001E6B30(n->m8);
                func_001E7360(n->m8, 0x4BB2084E, func_0011F548(a));
            } else {
                int u;
                if (func_001E7DE8(n->m8, 0x4B833E64, &u, 0)) {
                    a = func_00121E40(a, u, t);
                    func_001E8398(a, 0x0D7260FD, &t, 0);
                    func_001E6B30(n->m8);
                    func_001E7360(n->m8, 0x4BB2084E, func_0011F548(a));
                }
            }
        }
        n = next;
    }
}
