/* fuzzy: 95.8 */
struct Model_001355A8 {
    int m0;
    int m4;
    int m8;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual Model_001355A8* V12(int a);
};

extern "C" int func_00132538();
extern "C" void* func_0013C2E0(void* g, void* scene, int x);
extern "C" void func_001D3448(Model_001355A8* m, int id);
extern "C" void func_0013C708(void* g, int a);

struct Mesh_001355A8 {
    int m0;
    unsigned int m4;
    int m8;
    int mC;
    char pad10[0x10];
    void* m20;
    Model_001355A8* m24;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual Mesh_001355A8* V3(void* scene, int x);
    Mesh_001355A8* Clone(void* scene, int active, int x);
};

Mesh_001355A8* Mesh_001355A8::Clone(void* scene, int active, int x)
{
    Mesh_001355A8* n = V3(scene, x);
    if (!n) {
        return n;
    }
    n->m0 = func_00132538();
    n->m4 = m4 | 2;
    n->mC = mC;
    if (m20) {
        n->m20 = func_0013C2E0(m20, scene, x);
    }
    Model_001355A8* o = m24;
    if (o) {
        Model_001355A8* c = o->V12(0);
        if (c) {
            n->m24 = c;
            func_001D3448(c, n->m0);
            n->m4 &= ~0x40;
            if (active) {
                n->m4 |= 4;
            }
            if (n->m20) {
                func_0013C708(n->m20, c->m8);
            }
        } else {
            n->m4 &= ~0x40;
            n->m24 = 0;
            if (n->m20) {
                func_0013C708(n->m20, 0);
            }
        }
    }
    return n;
}
