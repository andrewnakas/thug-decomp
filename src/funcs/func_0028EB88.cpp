struct Vec_0028EB88 {
    float x, y, z, w;
    Vec_0028EB88() {}
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_0028EB88(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};
static inline void Sub(Vec_0028EB88& r, const Vec_0028EB88& a, const Vec_0028EB88& b)
{
    r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; r.w = a.w;
}
static inline void Add(Vec_0028EB88& r, const Vec_0028EB88& a, const Vec_0028EB88& b)
{
    r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; r.w = a.w;
}
struct Node_0028EB88 { char pad[0x50]; Vec_0028EB88 m50; };
struct Box_0028EB88 { char pad[0x20]; };
extern "C" void func_00102340(Box_0028EB88*, Vec_0028EB88*, Vec_0028EB88*);
extern "C" void func_001DA948(void*, Box_0028EB88*);
extern void* D_0038EE60;

struct Obj_0028EB88 {
    char pad0[0xC];
    Node_0028EB88* m_node;
    char pad1[0x590 - 0x10];
    void* m590;
    void Setup();
};

void Obj_0028EB88::Setup()
{
    Box_0028EB88 box;
    Vec_0028EB88 a;
    Vec_0028EB88 c(180.0f, 204.0f, 180.0f, 0.0f);
    Vec_0028EB88 b;
    Node_0028EB88* n = m_node;
    a.Set(n->m50.x - c.x, n->m50.y - c.y, n->m50.z - c.z, n->m50.w);
    Vec_0028EB88 d(180.0f, 96.0f, 180.0f, c.w);
    b.Set(n->m50.x + d.x, n->m50.y + d.y, n->m50.z + d.z, n->m50.w);
    func_00102340(&box, &a, &b);
    func_001DA948(m590, &box);
    D_0038EE60 = m590;
}
