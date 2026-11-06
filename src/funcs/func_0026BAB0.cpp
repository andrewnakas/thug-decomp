/* sym: __12Prm_0026BAB0 = 0x001E6978 */
/* sym: _$_12Prm_0026BAB0 = 0x001E6AE8 */
typedef int qword __attribute__((mode(TI)));

struct Prm_0026BAB0 {
    int m0;
    int m4;
    Prm_0026BAB0();
    ~Prm_0026BAB0();
};

struct Vec_0026BAB0 {
    qword q;
};

struct Skater_0026BAB0 {
    char pad[0x18];
    int m_index;
    int Index() { return m_index; }
};

struct Obj_0026BAB0 {
    char pad[0x50];
    Vec_0026BAB0 m_pos;
};

struct Node_0026BAB0 {
    int m0;
    int m4;
    char pad8[4];
    int mC;
    Vec_0026BAB0 m_pos;
    char pad20[0x30 - 0x20];
    int m30;
    int m34;
    unsigned int m38;
    unsigned int m3C;
    unsigned int m40;
    char pad44[0x84 - 0x44];
    unsigned int m84;
    Node_0026BAB0* m_next;
};

struct Mgr_0026BAB0 {
    int m0;
    Node_0026BAB0* m_head;
    int m8;
    int mC;
};

struct Game_0026BAB0 {
    char pad[0x2C];
    Mgr_0026BAB0* m2C;
};

extern Game_0026BAB0* D_0038FC78;
extern void* D_0038C608;
extern char D_00376228[];
extern char D_00376238[];
extern "C" int func_0026BF90(Node_0026BAB0* n, int arg);
extern "C" int func_0026BF80(Node_0026BAB0* n);
extern "C" void func_00184BC0(Skater_0026BAB0* sk, unsigned int name, int a, int b, int c, int d);
extern "C" void func_001F0210(unsigned int name, int a, int b, int c, int d);
extern "C" Obj_0026BAB0* func_00186CF8(void* mgr);
extern "C" void func_00183E90(Obj_0026BAB0* o, int id);
extern "C" void func_001E73C8(Prm_0026BAB0* p, const char* name, int v);
extern "C" void* func_001E55F8(const char* name, int a);
extern "C" void func_001853F0(Obj_0026BAB0* o, void* a, Prm_0026BAB0* p);
extern "C" void func_00185500(Obj_0026BAB0* o);
extern "C" void func_00184AB0(Obj_0026BAB0* o, unsigned int name, Prm_0026BAB0* p);
extern "C" void* func_00187B48(void* mgr, int id);
extern "C" void func_00184950(void* o);

void Update_0026BAB0(unsigned int mask, Skater_0026BAB0* skater, int arg)
{
    Mgr_0026BAB0* mgr = D_0038FC78->m2C;
    if (!mgr) {
        return;
    }
    for (Node_0026BAB0* n = mgr->m_head; n; n = n->m_next) {
        if (!n->m30) {
            continue;
        }
        int r = func_0026BF90(n, arg);
        if (mask & n->m40) {
            if (!r) {
                continue;
            }
            n->m40 &= ~mask;
            if (n->m34 == 0) {
                mgr->m8 = 1;
                mgr->mC = 1;
                if (skater) {
                    func_00184BC0(skater, n->m84, n->m4, 0, 0, 0);
                    n->m3C |= 1 << skater->Index();
                } else {
                    func_001F0210(n->m84, 0, 0, 0, 0);
                }
                mgr->mC = 0;
            } else if (skater) {
                Obj_0026BAB0* o = func_00186CF8(D_0038C608);
                func_00183E90(o, n->m34 + skater->Index());
                o->m_pos = n->m_pos;
                n->m38 |= 1 << skater->Index();
                Prm_0026BAB0 p;
                if (func_0026BF80(n)) {
                    func_001E73C8(&p, D_00376228, n->mC);
                }
                func_001853F0(o, func_001E55F8(D_00376238, 0), &p);
                func_00185500(o);
                Prm_0026BAB0 q;
                func_00184AB0(o, n->m84, &q);
            }
        } else {
            if (r) {
                continue;
            }
            n->m40 |= mask;
            if (n->m34 == 0) {
                mgr->m8 = 0;
                mgr->mC = 1;
                if (skater) {
                    func_00184BC0(skater, n->m84, n->m4, 0, 0, 0);
                    n->m3C &= ~(1 << skater->Index());
                } else {
                    func_001F0210(n->m84, 0, 0, 0, 0);
                }
                mgr->mC = 0;
            } else if (skater) {
                void* o = func_00187B48(D_0038C608, n->m34 + skater->Index());
                if (o) {
                    func_00184950(o);
                }
                n->m38 &= ~(1 << skater->Index());
            }
        }
    }
}
