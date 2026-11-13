/* force: {"kind": "ga", "before": [119, 166]} */
extern char D_003E6280[][0x800];
extern int D_003E8280[];
extern char D_003E7A80[];

struct Node_001A24C8 {
    int m0;
    int m_tag;
    int m8;
    Node_001A24C8* m_next;
};

static inline Node_001A24C8* Valid_001A24C8(Node_001A24C8* n)
{
    Node_001A24C8* r = 0;
    if (n->m_tag != -1) r = n;
    return r;
}

struct Obj_001A24C8 {
    char pad0[0x28];
    Node_001A24C8* m28;
    char pad2C[0x44 - 0x2C];
    int m44;
    char pad48[0x5C - 0x48];
    float m5C;
    char pad60[0x6C - 0x60];
    void* m6C;
    void Fn();
    int Count()
    {
        int n = 0;
        for (Node_001A24C8* p = Valid_001A24C8(m28); p; p = Valid_001A24C8(p->m_next))
            n++;
        return n;
    }
};

extern "C" void* func_0019EBD0(void* p);
extern "C" void func_0011EAA0(void* m, float t);
extern "C" void* func_0011D9E8(void* m);
extern "C" void func_0011E488(void* m, char* buf);
extern "C" void func_001A23A8(Obj_001A24C8* self, int i, char* buf, int* out);
extern "C" void func_001A2040(char (*bufs)[0x800], int* weights, void* p, char* out, int n);

void Obj_001A24C8::Fn()
{
    if (m44) {
        void* m = func_0019EBD0(m6C);
        if (m) {
            func_0011EAA0(m, m5C);
            int n = 0;
            Node_001A24C8* p = Valid_001A24C8(m28);
            while (p) {
                n++;
                p = Valid_001A24C8(p->m_next);
            }
            int i;
            for (i = 0; i < n; i++)
                func_001A23A8(this, i, D_003E6280[i], D_003E8280 + i);
            if (n > 1) {
                func_001A2040(D_003E6280, D_003E8280, func_0011D9E8(m), D_003E7A80, n);
                func_0011E488(m, D_003E7A80);
            } else {
                func_0011E488(m, D_003E6280[0]);
            }
        }
    }
}
