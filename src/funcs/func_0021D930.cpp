extern void* D_00392068;
extern void* D_0038FC78;

class Iter_0021D930 {
public:
    void* m_node;
    int m_index;
    Iter_0021D930() : m_index(0) {}
    virtual ~Iter_0021D930() {}
    virtual void Run();
};

class Iter2_0021D930 {
public:
    void* m_node;
    int m_index;
    Iter2_0021D930() : m_index(0) {}
    virtual ~Iter2_0021D930() {}
    virtual void Run();
};

struct Conn_0021D930 {
    char pad[0x18];
    void* m_obj;
    char pad1C[0x30 - 0x1C];
    int m_team;
};

extern "C" Conn_0021D930* func_002A53F8(void* net, Iter_0021D930* it, int a);
extern "C" Conn_0021D930* func_002A5490(void* net, Iter_0021D930* it, int a);
extern "C" bool func_002A5520(void* net, Iter2_0021D930* it);
extern "C" bool func_002A1A38(void* net);
extern "C" int func_002A1968(void* net);
extern "C" void* func_003315B8(void* p, int c, unsigned int n);
extern "C" void* func_0022E358(void* g);
extern "C" bool func_0024F540(void* p);
extern "C" void* func_00203360(void* p);
extern "C" int func_002392B8(void* p);

bool func_0021D930()
{
    Iter_0021D930 it;
    Iter2_0021D930 it2;
    void* net = D_00392068;
    int count = 0;
    Conn_0021D930* c;
    if (func_0024F540(func_0022E358(D_0038FC78))) {
        int scores[4];
        func_003315B8(scores, 0, sizeof(scores));
        for (c = func_002A53F8(net, &it, 0); c; c = func_002A5490(net, &it, 0))
            scores[c->m_team] += func_002392B8(func_00203360(c->m_obj));
        for (int i = 0; i < 4; i++)
            if (scores[i] > 0)
                count++;
        if (func_002A5520(net, &it2))
            return false;
    } else {
        int players = 0;
        for (c = func_002A53F8(net, &it, 0); c; c = func_002A5490(net, &it, 0)) {
            if (c->m_obj) {
                players++;
                if (func_002392B8(func_00203360(c->m_obj)) > 0)
                    count++;
            }
        }
        if (func_002A5520(net, &it2) || players == 1)
            return false;
    }
    if (func_002A1A38(net)) {
        if ((func_002A1968(net) == 1 || func_002A1968(net) == 2) && count == 0)
            return true;
    }
    return count == 1;
}
