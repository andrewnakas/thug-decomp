/* fuzzy: 95.1 */
/* blocked: game computes __in_chrg&1 into $s2 at entry; dtor loop rewrites, sibling Valid idioms and a C-style deleting dtor (as func_0017E0B0) keep the late andi. */
/* sym: _vt$12Mgr_00144FC0 = 0x0035EF30 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Node_00144FC0 {
public:
    int m0;
    unsigned int m4;
    int m8;
    Node_00144FC0* mC;
    int m10;
    virtual ~Node_00144FC0();
    Node_00144FC0* Valid()
    {
        if (m4 == 0xFFFFFFFF)
            return 0;
        return this;
    }
};

class Mgr_00144FC0 {
public:
    char pad[0x44];
    Node_00144FC0* m44;
    char pad48[0x28];
    virtual ~Mgr_00144FC0() = 0;
    virtual void V1();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Mgr_00144FC0::~Mgr_00144FC0()
{
    Node_00144FC0* n = m44->mC->Valid();
    while (n) {
        Node_00144FC0* next = n->mC->Valid();
        delete n;
        n = next;
    }
    delete m44;
}
