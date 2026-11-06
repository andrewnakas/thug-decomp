struct Comp_001ED1C0 {
    char m0;
    unsigned char m_type;
    short m2;
    int m4;
    union {
        int i;
        float f;
        unsigned int cs;
        void* p;
    } m8;
};

struct Eval_001ED1C0 {
    char pad[0x200];
};

struct Global_001ED1C0 {
    char m0;
    char m1;
    unsigned char m_type;
    char m3;
    int m4;
    int m8;
    union {
        int i;
        float f;
        int (*fn)(void* st, void* script);
    } mC;
};

extern Eval_001ED1C0 D_003F31D8;
extern Comp_001ED1C0 D_003F33D8;

extern "C" void func_001F13A0(Eval_001ED1C0* e);
extern "C" void func_001F13F0(Eval_001ED1C0* e, unsigned char* p);
extern "C" unsigned char* func_001ECA68(unsigned char* p);
extern "C" void func_001F2A00(Eval_001ED1C0* e);
extern "C" void func_001F2A20(Eval_001ED1C0* e);
extern "C" void func_001F28F8(Eval_001ED1C0* e, int op);
extern "C" void func_001F2998(Eval_001ED1C0* e, Comp_001ED1C0* c);
extern "C" void func_001F2A88(Eval_001ED1C0* e, void* result);
extern "C" unsigned char* func_001ECE50(unsigned char* p, void* params, Comp_001ED1C0* c);
extern "C" void func_001E6250(Comp_001ED1C0* c);
extern "C" Global_001ED1C0* func_001E5040(unsigned int cs);
extern "C" void* func_001EE408();
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" unsigned char* func_001ED6B8(void* st, unsigned char* p, void* params);
extern "C" void func_001E6AE8(void* st, int flags);
extern "C" unsigned int func_001EC7A0(unsigned char* p);
extern "C" Comp_001ED1C0* func_001E6DD0(void* params, unsigned int cs);
extern "C" void func_001EAFA8(Comp_001ED1C0* c);

extern "C" unsigned char* func_001ED1C0(unsigned char* p, void* params, void* result)
{
    int depth = 0;
    int had = 0;
    int expect = 1;
    int run = 1;
    func_001F13A0(&D_003F31D8);
    func_001F13F0(&D_003F31D8, p);
    p++;
    int dot = 0;
    do {
        p = func_001ECA68(p);
        unsigned char tok = *p;
        switch (tok) {
        case 0:
            break;
        case 14:
            if (!expect) {
                run = 0;
                break;
            }
            func_001F2A00(&D_003F31D8);
            p++;
            had = 0;
            expect = 1;
            depth++;
            break;
        case 15:
            p++;
            if (!depth) {
                run = 0;
                break;
            }
            func_001F2A20(&D_003F31D8);
            had = 1;
            expect = 0;
            depth--;
            break;
        case 23: {
            if (expect) goto operand;
            unsigned char* n = func_001ECE50(p, params, &D_003F33D8);
            if (D_003F33D8.m8.i >= 0) {
                run = 0;
                break;
            }
            if (!had) {
                run = 0;
                break;
            }
            func_001F28F8(&D_003F31D8, 10);
            p = n;
            had = 1;
            D_003F33D8.m8.i = -D_003F33D8.m8.i;
            func_001F2998(&D_003F31D8, &D_003F33D8);
            func_001E6250(&D_003F33D8);
            break;
        }
        case 26: {
            if (expect) goto operand;
            unsigned char* n = func_001ECE50(p, params, &D_003F33D8);
            if (D_003F33D8.m8.f < 0.0f) {
                if (!had) {
                    run = 0;
                    break;
                }
                func_001F28F8(&D_003F31D8, 10);
                p = n;
                had = 1;
                D_003F33D8.m8.f = -D_003F33D8.m8.f;
                func_001F2998(&D_003F31D8, &D_003F33D8);
                func_001E6250(&D_003F33D8);
                break;
            }
            run = 0;
            break;
        }
        case 22: {
            if (!expect) {
                run = 0;
                break;
            }
            p = func_001ECE50(p, params, &D_003F33D8);
            Global_001ED1C0* g = 0;
            if (!dot) g = func_001E5040(D_003F33D8.m8.cs);
            if (g) {
                switch (g->m_type) {
                case 2:
                    D_003F33D8.m_type = 2;
                    D_003F33D8.m8.f = g->mC.f;
                    func_001F2998(&D_003F31D8, &D_003F33D8);
                    break;
                case 1:
                    D_003F33D8.m_type = 1;
                    D_003F33D8.m8.i = g->mC.i;
                    func_001F2998(&D_003F31D8, &D_003F33D8);
                    break;
                case 6:
                    D_003F33D8.m_type = 6;
                    D_003F33D8.m8.i = g->mC.i;
                    func_001F2998(&D_003F31D8, &D_003F33D8);
                    break;
                case 5:
                    D_003F33D8.m_type = 5;
                    D_003F33D8.m8.i = g->mC.i;
                    func_001F2998(&D_003F31D8, &D_003F33D8);
                    break;
                case 3:
                    D_003F33D8.m_type = 3;
                    D_003F33D8.m8.i = g->mC.i;
                    func_001F2998(&D_003F31D8, &D_003F33D8);
                    break;
                case 4:
                    D_003F33D8.m_type = 4;
                    D_003F33D8.m8.i = g->mC.i;
                    func_001F2998(&D_003F31D8, &D_003F33D8);
                    break;
                case 10:
                    D_003F33D8.m_type = 10;
                    D_003F33D8.m8.i = g->mC.i;
                    func_001F2998(&D_003F31D8, &D_003F33D8);
                    break;
                case 12:
                    D_003F33D8.m_type = 12;
                    D_003F33D8.m8.i = g->mC.i;
                    func_001F2998(&D_003F31D8, &D_003F33D8);
                    break;
                case 8: {
                    void* script = func_001EE408();
                    D_003F33D8.m_type = 1;
                    void* st = func_001E6978(func_001190D0(8));
                    p = func_001ED6B8(st, p, params);
                    D_003F33D8.m8.i = g->mC.fn(st, script);
                    if (st) func_001E6AE8(st, 3);
                    func_001F2998(&D_003F31D8, &D_003F33D8);
                    break;
                }
                case 9:
                    break;
                default:
                    func_001F2998(&D_003F31D8, &D_003F33D8);
                    break;
                }
            } else {
                func_001F2998(&D_003F31D8, &D_003F33D8);
            }
            had = 1;
            expect = 0;
            D_003F33D8.m_type = 0;
            D_003F33D8.m8.i = 0;
            break;
        }
        case 3:
        case 27:
        case 28:
        case 30:
        case 31:
        case 48:
            if (!expect) {
                run = 0;
                break;
            }
        operand:
            p = func_001ECE50(p, params, &D_003F33D8);
            had = 1;
            expect = 0;
            func_001F2998(&D_003F31D8, &D_003F33D8);
            func_001E6250(&D_003F33D8);
            break;
        case 45: {
            if (!expect) {
                run = 0;
                break;
            }
            p += 2;
            unsigned int cs = func_001EC7A0(p);
            p += 4;
            if (params) {
                Comp_001ED1C0* c = func_001E6DD0(params, cs);
                if (c) {
                    D_003F33D8.m_type = c->m_type;
                    D_003F33D8.m8.i = c->m8.i;
                    func_001EAFA8(&D_003F33D8);
                    func_001F2998(&D_003F31D8, &D_003F33D8);
                    D_003F33D8.m_type = 0;
                    D_003F33D8.m8.i = 0;
                }
            }
            had = 1;
            expect = 0;
            break;
        }
        case 44:
            if (!expect) {
                run = 0;
                break;
            }
            p++;
            if (params) {
                D_003F33D8.m_type = 10;
                D_003F33D8.m8.p = params;
                func_001F2998(&D_003F31D8, &D_003F33D8);
            }
            had = 1;
            expect = 0;
            break;
        case 5:
        case 7:
        case 8:
        case 10:
        case 11:
        case 12:
        case 13:
        case 18:
        case 20:
        case 50:
        case 51:
            func_001F28F8(&D_003F31D8, tok);
            expect = 1;
            p++;
            if (tok == 8) dot = 1;
            else dot = 0;
            had = 0;
            break;
        case 1:
        case 6:
            p++;
            break;
        case 2:
            p += 5;
            break;
        }
    } while (run);
    func_001F2A88(&D_003F31D8, result);
    return p;
}
