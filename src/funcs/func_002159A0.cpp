extern void* D_00392068;

extern "C" void* func_002A39D8(void* net);
extern "C" void* func_002A39E0(void* net, int a);
extern "C" void func_001F9578(void* p, int i);
extern "C" void func_001F9588(void* p, int i);

// Iterator with vtable D_00366B58: the class of func_002016D8 (its vtable name is
// already mapped in cxx_symbols_lane2.txt). Here the destructor is inlined.
class Iter_002159A0 {
public:
    void* m_node;
    int m_index;
    Iter_002159A0() : m_index(0) {}
    virtual ~Iter_002159A0() {}
    virtual void Run();
};

struct Conn_002159A0 {
    char pad[0x20EC];
    char m_in[0x34FC - 0x20EC];
    char m_out[0x10];
};

extern "C" Conn_002159A0* func_00200EC0(void* mgr, Iter_002159A0* it);
extern "C" Conn_002159A0* func_00200EF8(void* mgr, Iter_002159A0* it);

bool Cmd_002159A0(void* params, void* script)
{
    Iter_002159A0 it;
    void* net = D_00392068;
    void* mgr = func_002A39D8(net);
    if (!mgr) {
        mgr = func_002A39E0(net, 0);
        if (!mgr) {
            return true;
        }
    }
    for (Conn_002159A0* conn = func_00200EC0(mgr, &it); conn; conn = func_00200EF8(mgr, &it)) {
        void* in = conn->m_in;
        void* out = conn->m_out;
        for (int i = 0; i < 256; i++) {
            func_001F9578(in, i);
            func_001F9588(in, i);
        }
        for (int i = 0; i < 256; i++) {
            func_001F9578(in, i);
            func_001F9588(in, i);
        }
        for (int i = 0; i < 256; i++) {
            func_001F9578(out, i);
            func_001F9588(out, i);
        }
        for (int i = 0; i < 256; i++) {
            func_001F9578(out, i);
            func_001F9588(out, i);
        }
    }
    return true;
}
