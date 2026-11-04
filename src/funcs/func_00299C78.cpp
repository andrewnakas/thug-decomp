typedef int qword __attribute__((mode(TI)));

union Vec_00299C78 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Node_00299C78 {
    char pad[0x10];
    Vec_00299C78 pos;
    char pad2[0x2C - 0x20];
    Node_00299C78* next;
    Node_00299C78* prev;
};

struct Inner_00299C78 {
    char pad[0x18];
    void* m18;
};
struct Mgr_00299C78 {
    Inner_00299C78* m0;
};

extern Vec_00299C78 D_00453140;
extern "C" Node_00299C78* func_00299B80(void* self, int id);
extern "C" bool func_00298378(Vec_00299C78* a, Vec_00299C78* b);
extern "C" bool func_002982F8(Vec_00299C78* a, Vec_00299C78* b);
extern "C" bool func_002CADB8(Vec_00299C78* v, float r);
extern "C" void func_00298E50(Node_00299C78* n);
extern "C" void func_002987C8(Node_00299C78* n, Vec_00299C78* a, Vec_00299C78* b, float f);
extern "C" void func_00298508(Node_00299C78* n, Vec_00299C78* a, Vec_00299C78* b, float f);
extern "C" Mgr_00299C78* func_002C0368();
extern "C" void func_00133D48(void* p, int a);

struct Obj_00299C78 {
    bool Move(int id, Vec_00299C78* pos, bool flag);
};

bool Obj_00299C78::Move(int id, Vec_00299C78* pos, bool flag)
{
    bool ok = true;
    Node_00299C78* n = func_00299B80(this, id);
    if (n->next && !func_00298378(pos, &n->next->pos))
        ok = false;
    if (n->prev && !func_00298378(pos, &n->prev->pos))
        ok = false;
    Vec_00299C78 tmp;
    tmp.q = pos->q;
    bool ok2 = true;
    if (func_002CADB8(&tmp, 10.0f) != true)
        ok = false;
    if (n->next && func_002982F8(pos, &n->next->pos))
        ok2 = false;
    if (n->prev && func_002982F8(pos, &n->prev->pos))
        ok2 = false;
    if (ok2) {
        n->pos.q = pos->q;
        func_00298E50(n);
        func_002987C8(n, &D_00453140, &D_00453140, 0.0f);
        func_00298508(n, &D_00453140, &D_00453140, 0.0f);
        if (n->prev)
            func_00298508(n->prev, &D_00453140, &D_00453140, 0.0f);
        if (flag)
            func_00133D48(func_002C0368()->m0->m18, 0);
    }
    return ok;
}
