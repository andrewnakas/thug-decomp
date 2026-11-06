/* fuzzy: 94.9 */
struct Mesh_00133170;

extern "C" int func_00134F08(Mesh_00133170* m);
extern "C" void func_00114EB8(void* table, int* key);
extern "C" void func_00135048(Mesh_00133170* m, int a);
extern "C" int func_00135580(Mesh_00133170* m, int flags);

class LinkNode134CD8 {
public:
    int m0;
    int m4;
    int m8;
    LinkNode134CD8* m_prev;
    LinkNode134CD8* m_next;
    virtual ~LinkNode134CD8();
    virtual void Run();
    LinkNode134CD8* Next()
    {
        LinkNode134CD8* n = m_prev;
        return n->m4 == -1 ? 0 : n;
    }
};

struct Scene_00133170 {
    char pad0[0xD0];
    void* m_D0;
    char padD4[0x1A0];
    int m_274;
    LinkNode134CD8* m_278;
    LinkNode134CD8* m_27C;
    int Swap();
    void Remove(Mesh_00133170* m)
    {
        int key = func_00134F08(m);
        func_00114EB8(m_D0, &key);
    }
};

extern "C" void func_00132FF8(Scene_00133170* self, Mesh_00133170* m);
extern "C" void func_00133D48(Scene_00133170* self, LinkNode134CD8* list);

int Scene_00133170::Swap()
{
    int count = 0;
    for (LinkNode134CD8* q = m_27C->Next(); q; q = q->Next()) {
        count++;
    }
    if (!count) {
        return 0;
    }
    m_274 ^= 1;
    LinkNode134CD8* out;
    LinkNode134CD8* in;
    if (m_274) {
        in = m_27C;
        out = m_278;
    } else {
        in = m_278;
        out = m_27C;
    }
    LinkNode134CD8* next;
    LinkNode134CD8* p;
    for (p = out->Next(); p; p = next) {
        Mesh_00133170* m = (Mesh_00133170*)p->m4;
        next = p->Next();
        func_00135580(m, 0x10);
        Remove(m);
        func_00135048(m, 0);
    }
    for (p = in->Next(); p; p = next) {
        Mesh_00133170* m = (Mesh_00133170*)p->m4;
        next = p->Next();
        func_00135580(m, 4);
        func_00132FF8(this, m);
        func_00135048(m, 1);
    }
    func_00133D48(this, out);
    return m_274;
}
