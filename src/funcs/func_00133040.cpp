extern "C" void* func_001046B0(int size);

struct Mesh_00133040;

extern "C" int func_00134F08(Mesh_00133040* m);
extern "C" Mesh_00133040* func_00134BB8(void* table, int* key, int a);
extern "C" void func_00114EB8(void* table, int* key);
extern "C" void func_00135048(Mesh_00133040* m, int a);
extern "C" void func_00135580(Mesh_00133040* m, int flags);

class LinkNode134CD8 {
public:
    int m0;
    Mesh_00133040* m4;
    int m8;
    LinkNode134CD8* m_prev;
    LinkNode134CD8* m_next;
    LinkNode134CD8(Mesh_00133040* d)
    {
        m_prev = this;
        m_next = this;
        m4 = d;
        m8 = 0;
    }
    virtual ~LinkNode134CD8();
    virtual void Run();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
    void InsertBefore(LinkNode134CD8* head)
    {
        LinkNode134CD8* last = head->m_next;
        m_prev = head;
        m_next = last;
        head->m_next->m_prev = this;
        head->m_next = this;
    }
};

struct Scene_00133040 {
    char pad0[0xD0];
    void* m_D0;
    char padD4[0x1A4];
    LinkNode134CD8* m_278;
    LinkNode134CD8* m_27C;
    Mesh_00133040* Replace(Mesh_00133040* m);
};

extern "C" void func_00132FF8(Scene_00133040* self, Mesh_00133040* m);

Mesh_00133040* Scene_00133040::Replace(Mesh_00133040* m)
{
    int key = func_00134F08(m);
    Mesh_00133040* old = func_00134BB8(m_D0, &key, 1);
    if (old) {
        int oldKey = func_00134F08(old);
        func_00114EB8(m_D0, &oldKey);
        func_00135048(old, 0);
        func_00135580(old, 0x10);
        (new LinkNode134CD8(old))->InsertBefore(m_278);
    }
    func_00135580(m, 4);
    func_00132FF8(this, m);
    (new LinkNode134CD8(m))->InsertBefore(m_27C);
    return old;
}
