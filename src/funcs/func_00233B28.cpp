/* sym: _vt$13Iter_00233B28 = 0x00371C78 */
struct Net_00233B28;
extern Net_00233B28* D_00392068;
extern void* D_00388A70;
extern char D_00373160[];
extern char D_00373178[];

class Iter_00233B28 {
public:
    void* m_node;
    int m_index;
    Iter_00233B28() : m_index(0) {}
    virtual ~Iter_00233B28() {}
    virtual void Run();
};

struct Mgr_00233B28 {
    char pad0[0x260];
    void* m260;
};

struct Conn_00233B28 {
    char pad0[0x18];
    void* m18;
    int m1C;
};

extern "C" void* func_001046B0(int size);
extern "C" void* func_00122E00(void* p);
extern "C" int func_002A1A38(Net_00233B28* s);
extern "C" Conn_00233B28* func_002A5248(Net_00233B28* net, void* id);
extern "C" Conn_00233B28* func_002A52F0(Net_00233B28* net, unsigned char id);
extern "C" void func_00123110(void* s, char* data, int len);
extern "C" void func_00123428(void* s, int v);
extern "C" Mgr_00233B28* func_00185578(void* obj, unsigned int name);
extern "C" int func_0013F048(void* m, void* o, char* a, unsigned int b);
extern "C" void func_002B1EC8(Conn_00233B28* c, char* data, int len);
extern "C" Conn_00233B28* func_002A53F8(Net_00233B28* net, Iter_00233B28* it, int a);
extern "C" Conn_00233B28* func_002A5490(Net_00233B28* net, Iter_00233B28* it, int a);
extern "C" int func_002B1FC8(Conn_00233B28* c);
extern "C" int func_002B1F58(Conn_00233B28* c);
extern "C" void func_002006C8(void* client, int conn, int id, int size, int data, char* name, int queue, int a, int b);
extern "C" void func_0010A8D8(void* pool, void* p);

struct Cmd_00233B28 {
    char* m0;
    int m4;
    long m8;
    void* m10;
    void* m14;
    int Run();
};

int Cmd_00233B28::Run()
{
    Net_00233B28* net = D_00392068;
    void* s = func_00122E00(func_001046B0(0x44A0));
    char* data = m0;
    int len = m8;
    Conn_00233B28* c;
    if (func_002A1A38(net)) {
        c = func_002A5248(net, m14);
    } else {
        c = func_002A52F0(net, *data);
        data++;
        len--;
    }
    if (!c)
        return 3;
    Conn_00233B28* o = (Conn_00233B28*)c->m18;
    if (!o)
        return 3;
    func_00123110(s, data, len);
    func_00123428(s, 1);
    func_0013F048(func_00185578(o, 0x286A8D26)->m260, s, D_00373160, 0xC4E78E22);
    if (func_002A1A38(net)) {
        Iter_00233B28 it;
        void* client = m10;
        Conn_00233B28* self = func_002A5248(net, m14);
        func_002B1EC8(self, m0, m8);
        for (o = func_002A53F8(net, &it, 1); o; o = func_002A5490(net, &it, 1)) {
            if (func_002B1FC8(o))
                continue;
            if (o == self)
                continue;
            func_002006C8(client, o->m1C, 0x7E, 0x4499, func_002B1F58(self), D_00373178, 9, 0, 1);
        }
    }
    func_0010A8D8(D_00388A70, s);
    return 1;
}
