extern void* D_00392068;
extern void* D_0038FC78;

class Iter_0021D7A0 {
public:
    void* m_node;
    int m_index;
    Iter_0021D7A0() : m_index(0) {}
    virtual ~Iter_0021D7A0() {}
    virtual void Run();
};

struct Conn_0021D7A0 {
    char pad[0x18];
    void* m_obj;
    char pad1C[0x30 - 0x1C];
    int m_team;
};

extern "C" Conn_0021D7A0* func_002A53F8(void* net, Iter_0021D7A0* it, int a);
extern "C" Conn_0021D7A0* func_002A5490(void* net, Iter_0021D7A0* it, int a);
extern "C" void* func_003315B8(void* p, int c, unsigned int n);
extern "C" int func_0021B318();
extern "C" void* func_0022E358(void* g);
extern "C" bool func_0024F540(void* p);
extern "C" void* func_00203360(void* p);
extern "C" int func_002392B8(void* p);

bool func_0021D7A0()
{
    Iter_0021D7A0 it;
    void* net = D_00392068;
    int target = func_0021B318();
    Conn_0021D7A0* c;
    if (func_0024F540(func_0022E358(D_0038FC78))) {
        int scores[4];
        func_003315B8(scores, 0, sizeof(scores));
        for (c = func_002A53F8(net, &it, 0); c; c = func_002A5490(net, &it, 0))
            scores[c->m_team] += func_002392B8(func_00203360(c->m_obj));
        for (int i = 0; i < 4; i++) {
            if (scores[i] >= target)
                return true;
        }
    } else {
        for (c = func_002A53F8(net, &it, 0); c; c = func_002A5490(net, &it, 0)) {
            if (c->m_obj && func_002392B8(func_00203360(c->m_obj)) >= target)
                return true;
        }
    }
    return false;
}
