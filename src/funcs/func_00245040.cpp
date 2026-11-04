extern void* D_00392068;
extern void* D_0038FC78;

class Iter_00245040 {
public:
    void* m_node;
    int m_index;
    Iter_00245040() : m_index(0) {}
    virtual ~Iter_00245040() {}
    virtual void Run();
};

struct Obj_00245040 {
    char pad[0x104];
    unsigned int m_flags;
    char pad108[0x150 - 0x108];
    int m_150;
};

struct Conn_00245040 {
    char pad[0x18];
    Obj_00245040* m_obj;
};

struct Self_00245040 {
    char pad[0x28];
    int m_mode;
};

extern "C" Conn_00245040* func_002A53F8(void* net, Iter_00245040* it, int a);
extern "C" Conn_00245040* func_002A5490(void* net, Iter_00245040* it, int a);
extern "C" void* func_00185578(Obj_00245040* o, unsigned int id);
extern "C" void* func_0022E358(void* g);
extern "C" unsigned int func_0024F938(void* p);
extern "C" bool func_00290810(void* p);
extern "C" bool func_00290820(void* p);

bool func_00245040(Self_00245040* self)
{
    void* net = D_00392068;
    void* game = D_0038FC78;
    Iter_00245040 it;
    for (Conn_00245040* c = func_002A53F8(net, &it, 0); c; c = func_002A5490(net, &it, 0)) {
        Obj_00245040* o = c->m_obj;
        void* p = func_00185578(o, 0xB1D5A3E1);
        if (func_0024F938(func_0022E358(game)) == 0x9D65D0E7) {
            if (o->m_150 != 0)
                continue;
            if (o->m_flags & 4)
                continue;
        }
        if (self->m_mode != 0) {
            if (self->m_mode != 1)
                continue;
            if (!func_00290810(p))
                return false;
        } else {
            if (!func_00290820(p))
                return false;
        }
    }
    return true;
}
