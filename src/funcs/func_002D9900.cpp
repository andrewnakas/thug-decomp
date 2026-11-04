struct Elem_002D9900 {
    char pad[0x50];
};

struct X_002D9900 {
    char pad0[0x14];
    char m14[0x68];
    Elem_002D9900 m7C[5];
};

struct Mgr_002D9900 {
    char pad0[0x10];
    X_002D9900* m10;
};

extern Mgr_002D9900* D_00392068;
extern "C" int func_001E8A30(void* p, unsigned int key, unsigned int* out, int v);
extern "C" void func_002DA938(Elem_002D9900* e);
extern "C" void func_002DACC8(Elem_002D9900* e, int v);
extern "C" void func_002DA2C0(void* p);

bool Cmd_002D9900(void* params)
{
    X_002D9900* x = D_00392068->m10;
    unsigned int h;
    func_001E8A30(params, 0x5EF31148, &h, 1);
    switch (h) {
    case 0x5299291B:
        func_002DACC8(&x->m7C[4], 1);
        break;
    case 0xEF20D3A1:
        func_002DA938(&x->m7C[0]);
        func_002DACC8(&x->m7C[0], 0);
        break;
    case 0xCB95928F:
        func_002DA938(&x->m7C[2]);
        func_002DACC8(&x->m7C[2], 0);
        break;
    case 0x67F1AE8A:
        func_002DA938(&x->m7C[3]);
        func_002DACC8(&x->m7C[3], 0);
        break;
    case 0x9FE64312:
        func_002DA938(&x->m7C[1]);
        func_002DACC8(&x->m7C[1], 0);
        break;
    case 0xFEF84FFF:
        func_002DA2C0(x->m14);
        break;
    }
    return true;
}
