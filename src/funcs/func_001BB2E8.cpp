extern "C" int func_00229668(int id, int flag);
extern "C" void* func_001E55B8(unsigned int id, int flags);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8180(void* params, unsigned int name, void** out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_0022EEC0(void* mgr, void* p);
extern "C" void func_00184BC0(void* obj, unsigned int name, int idx, int a, int b, void* c);
extern void* D_0038FC78;

struct List_001BB2E8 {
    int m_pad[3];
    int m_count;
};

extern "C" void* func_001E9378(void* scr, int arg);

struct Obj_001BB2E8 {
    int m_pad[6];
    int m18;
};

struct C_001BB2E8 {
    int m_pad[3];
    void* mC;
    int m10[8];
    int m30;
    void Select(int a, unsigned int id, List_001BB2E8* list, Obj_001BB2E8* o);
};

void C_001BB2E8::Select(int a, unsigned int id, List_001BB2E8* list, Obj_001BB2E8* o)
{
    void* p = 0;
    int idx;
    if (!list) {
        idx = func_00229668(id, 1);
        p = func_001E9378(func_001E55B8(0xC472ECC5, 0), idx);
    } else {
        idx = list->m_count;
        while (--idx != -1) {
            unsigned int v;
            p = func_001E9378(list, idx);
            func_001E8398(p, 0xA1DC81F9, &v, 0);
            if (v == id) break;
        }
    }
    void* w = 0;
    if (o) {
        void* s = func_001E55B8(0xC472ECC5, 0);
        void* q = func_001E9378(s, func_00229668(o->m18, 1));
        if (q) func_001E8180(q, 0x5180A4DB, &w, 0);
    }
    unsigned int n = 0;
    func_001E8398(p, 0x2CA8A299, &n, 0);
    if (!n) return;
    if (func_0022EEC0(D_0038FC78, p)) return;
    m30 = a;
    void* obj = mC;
    unsigned int nn = n;
    int b1 = func_001E8708(p, 0x20209C31);
    int b2 = func_001E8708(p, 0x23627FD7);
    func_00184BC0(obj, nn, idx, b1, b2, w);
}
