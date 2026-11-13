/* fuzzy: 82.1 */
/* sym: _$_13Item_002A0840 = 0x002B3168 */
/* Not matching (parked): built with default flags (matched same-file neighbours func_0029FC98 and func_002A1588
   break under -fno-gcse). The one blocker is gcse constant propagation: cse1 puts `any` (0, set in the first block)
   into the copied loop-entry Valid test, gcse cprop folds it to constant 0, and jump2 then merges the entry test into
   the latch copy (10 words short). The game keeps `sltu v0, a3, v0` (a3 = any) in the entry copy; the same source
   under -fno-gcse produces it exactly. No natural source shape found that keeps the zero out of cprop. */
extern char D_00366B58[];

struct Iter_002A0840 {
    int m0;
    int m4;
    void* m8;
    Iter_002A0840() { m8 = D_00366B58; m4 = 0; }
    ~Iter_002A0840() { m8 = D_00366B58; }
};

struct Item_002A0840 {
    char pad[0x18];
    unsigned int m18;
    ~Item_002A0840();
};

struct Node_002A0840 {
    int m0;
    Item_002A0840* data;
    int m8;
    Node_002A0840* next;
    int m10;
    virtual ~Node_002A0840();
    Node_002A0840* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
};

struct Conn_002A0840 {
    char pad[0x1804];
    unsigned int m1804;
};

struct Sess_002A0840 {
    char pad[0x18];
    Conn_002A0840* m18[2];
    char pad20[0xF4 - 0x20];
    Node_002A0840 mF4;
};

struct Pool_002A0840 {
    char pad[0x3EC];
    int m3EC;
};

extern Pool_002A0840* D_00388A70;
extern void* D_0038FC78;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_002A41D0(Sess_002A0840* s, Item_002A0840* d);
extern "C" void* func_00200EC0(Conn_002A0840* c, Iter_002A0840* it);
extern "C" void func_00202688(void* p, int v);
extern "C" void* func_0022DE70(void* g, int i);
extern "C" void func_00206920(void* p);
extern "C" void func_002A8598(Sess_002A0840* s);

struct Obj_002A0840 {
    char pad[0x20];
    Sess_002A0840* m20;
    void Purge();
};

void Obj_002A0840::Purge()
{
    func_0010A950(D_00388A70, D_00388A70->m3EC);
    Sess_002A0840* s = m20;
    Iter_002A0840 it;
    void* g = D_0038FC78;
    int any = 0;
    Node_002A0840* n = s->mF4.next->Valid();
    Node_002A0840* nx;
    Item_002A0840* d;
    while (n && (nx = n->next->Valid(), d = n->data, d->m18 <= s->m18[0]->m1804)) {
        func_002A41D0(s, d);
        delete d;
        delete n;
        any = 1;
        n = nx;
    }
    if (any) {
        for (int i = 0; i < 2; i++) {
            if (s->m18[i]) {
                void* r = func_00200EC0(s->m18[i], &it);
                if (r) func_00202688(r, 0);
            }
        }
        for (int i = 0; i < 8; i++) {
            void* p = func_0022DE70(g, i);
            if (p) func_00206920(p);
        }
        func_002A8598(s);
    }
    func_0010A9B0(D_00388A70);
}
