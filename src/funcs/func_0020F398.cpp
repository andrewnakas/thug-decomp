extern void* D_00388A70;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void func_0010A8D8(void* pool, void* p);

struct Color_0020F398 {
    unsigned char r, g, b, a;
    Color_0020F398() {}
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    static void operator delete[](void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Item_0020F398 {
    char pad0[8];
    int m_id;
};

extern "C" void func_00132A80(void* list);
extern "C" Item_0020F398* func_00132A90(void* list, int a);
extern "C" void* func_00134F18(Item_0020F398* item);
extern "C" int func_0013C7E0(void* mesh);
extern "C" void func_0013C8A8(void* mesh, Color_0020F398* buf);
extern "C" void func_0013C958(void* mesh, Color_0020F398* buf);
extern "C" float func_0020F358(float v, float base, float t);

struct Self_0020F398 {
    char pad0[0xD0];
    void* m_list;

    void Tint(int id, float base, float t);
};

void Self_0020F398::Tint(int id, float base, float t)
{
    void* list = m_list;
    if (!list)
        return;
    func_00132A80(list);
    Item_0020F398* item;
    for (item = func_00132A90(list, 0); item; item = func_00132A90(list, 0)) {
        void* mesh = func_00134F18(item);
        if (!mesh)
            continue;
        if (id && id != item->m_id)
            continue;
        int n = func_0013C7E0(mesh);
        if (!n)
            continue;
        Color_0020F398* buf = new Color_0020F398[n];
        func_0013C8A8(mesh, buf);
        Color_0020F398* p = buf;
        if (base != 0.0f || t != 0.0f) {
            for (int i = 0; i < n; i++) {
                Color_0020F398 c;
                c.a = p->a;
                c.r = (unsigned char)func_0020F358(p->r, base, t);
                c.g = (unsigned char)func_0020F358(p->g, base, t);
                c.b = (unsigned char)func_0020F358(p->b, base, t);
                *p = c;
                p++;
            }
        }
        func_0013C958(mesh, buf);
        delete[] buf;
    }
}
