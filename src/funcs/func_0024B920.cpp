extern void* D_00392068;
extern void* D_0038FC78;
extern char D_003741B0[];

class Iter_0024B920 {
public:
    void* m_node;
    int m_index;
    Iter_0024B920() : m_index(0) {}
    virtual ~Iter_0024B920() {}
    virtual void Run();
};

struct Obj_0024B920 {
    char pad[0x150];
    int m_150;
};

struct Conn_0024B920 {
    char pad[0x18];
    Obj_0024B920* m_obj;
};

struct Self_0024B920 {
    char pad[0x28];
    int m_mode;
    char pad2C[0x54 - 0x2C];
    int m_54;
    char pad58[0x8C - 0x58];
    int m_8C;
    char pad90[0xA0 - 0x90];
    int m_A0;
};

extern "C" Conn_0024B920* func_002A53F8(void* net, Iter_0024B920* it, int a);
extern "C" Conn_0024B920* func_002A5490(void* net, Iter_0024B920* it, int a);
extern "C" void* func_00185578(Obj_0024B920* o, unsigned int id);
extern "C" void* func_0022E358(void* g);
extern "C" unsigned int func_0024F938(void* p);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" bool func_00250428();
extern "C" bool func_00245040(Self_0024B920* self);
extern "C" bool func_002A39F8(void* net);
extern "C" bool func_002A7EE0(void* net);
extern "C" bool func_002A19A8(void* net);
extern "C" bool func_00290810(void* p);
extern "C" void func_00290720(void* p, int a);
extern "C" bool func_002A8560(void* net);

bool func_0024B920(Self_0024B920* self)
{
    if (func_0024F938(func_0022E358(D_0038FC78)) == func_001F0D78(D_003741B0))
        return func_00250428() && func_00245040(self);
    Iter_0024B920 it;
    void* net = D_00392068;
    if (!func_002A39F8(net))
        return true;
    if (self->m_A0 || (!func_002A7EE0(net) && func_002A19A8(net)))
        return false;
    if (self->m_mode == 2)
        return self->m_54 <= 0;
    if (func_00245040(self) && self->m_54 <= 0)
        return true;
    for (Conn_0024B920* c = func_002A53F8(net, &it, 0); c; c = func_002A5490(net, &it, 0)) {
        Obj_0024B920* o = c->m_obj;
        void* p = func_00185578(o, 0xB1D5A3E1);
        if (!func_00290810(p) && o->m_150 == 0 && self->m_mode != 2 && self->m_54 <= 0) {
            self->m_8C = 1;
            func_00290720(p, 0);
        }
    }
    return func_002A8560(net);
}
