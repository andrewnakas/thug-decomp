/* fuzzy: 86.0 */
struct Vec_0029B748 {
    float x, y, z, w;
};

struct Node_0029B748 {
    char pad[0x10];
    Vec_0029B748 pos;
    char pad2[0x2C - 0x20];
    Node_0029B748* next;
};

struct Grp_0029B748 {
    char pad[0xC];
    Node_0029B748* head;
};

struct Tmp_0029B748 {
    char d[0x10];
};

extern int D_00391EC8;
extern "C" bool func_00298278(Vec_0029B748* a, Vec_0029B748* b);
extern "C" bool func_002982F8(Vec_0029B748* a, Vec_0029B748* b);
extern "C" bool func_00298160(Vec_0029B748* a, Vec_0029B748* b, Vec_0029B748* c);
extern "C" void* func_002978F8(unsigned int type);
extern "C" void func_00297BF8(Tmp_0029B748* out, Vec_0029B748* a, Vec_0029B748* b, void* obj, unsigned int type, int c, int d);
extern "C" int func_001E53A0(unsigned int name, int a);
extern "C" void func_00134FD8(void* obj, unsigned int v);

struct Obj_0029B748;
extern "C" void func_0029B6E0(Obj_0029B748* o);

struct Obj_0029B748 {
    char pad[0x28];
    Grp_0029B748* m28;
    char pad2[0x30 - 0x2C];
    unsigned int m30;
    void* m34;
    void Update(Vec_0029B748* p);
};

void Obj_0029B748::Update(Vec_0029B748* p)
{
    Grp_0029B748* g = m28;
    if (!g)
        return;
    Node_0029B748* n = g->head;
    if (!n)
        return;
    Vec_0029B748* pos = &n->pos;
    unsigned int type = 0x5DC3C690;
    if (func_00298278(pos, p)) {
        if (func_002982F8(pos, p)) {
            func_0029B6E0(this);
            return;
        }
        type = 0x8DDA17D6;
    } else if (n->next) {
        if (!func_00298160(&n->next->pos, pos, p))
            type = 0x8DDA17D6;
    }
    if (!m34 || type != m30) {
        func_0029B6E0(this);
        m34 = func_002978F8(type);
        m30 = type;
    }
    Tmp_0029B748 t;
    func_00297BF8(&t, &n->pos, p, m34, m30, 0, 0);
    if (type == 0x8DDA17D6) {
        int cnt = func_001E53A0(0xEEBE4394, 0);
        unsigned int dir = 0xFFFFFFFF;
        if (!(D_00391EC8 < cnt / 2))
            dir = 0;
        int next = D_00391EC8 + 1;
        D_00391EC8 = next;
        if (!(next < cnt))
            D_00391EC8 = 0;
        func_00134FD8(m34, dir);
    }
}
