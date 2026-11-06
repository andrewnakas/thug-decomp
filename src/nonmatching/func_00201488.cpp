/* fuzzy: 95.6 */
// Iterator with vtable D_00366B58: the class of func_002016D8 (its vtable name is
// already mapped in cxx_symbols_lane2.txt). Here the destructor is inlined.
class Node104D78_002016D8 {
public:
    void* m_node;
    int m_index;
    Node104D78_002016D8() : m_index(0) {}
    virtual ~Node104D78_002016D8() {}
    virtual void Run();
};

struct Conn_00201488 {
    char pad[0x34FC];
    char m_out[0x10];
};

struct Mgr_00201488 {
    char pad[0x1838];
    void* m_m1838;
};

extern "C" int func_002013E8();
extern "C" int func_001FA1A8(void* p);
extern "C" int func_001F9570(void* p);
extern "C" int func_00202BC0(Conn_00201488* c);
extern "C" Conn_00201488* func_00200EC0(Mgr_00201488* mgr, Node104D78_002016D8* it);
extern "C" Conn_00201488* func_00200EF8(Mgr_00201488* mgr, Node104D78_002016D8* it);
extern "C" bool func_00202778(Conn_00201488* c);
extern "C" bool func_00202758(Conn_00201488* c);

bool IsSaturated_00201488(Mgr_00201488* mgr, Conn_00201488* conn)
{
    Node104D78_002016D8 it;
    void* out = conn->m_out;
    if (func_002013E8() >= func_001FA1A8(mgr->m_m1838) || func_001F9570(out) >= func_00202BC0(conn)) {
        return true;
    }
    int count = 0;
    for (Conn_00201488* c = func_00200EC0(mgr, &it); c; c = func_00200EF8(mgr, &it)) {
        if (func_00202778(c) && !func_00202758(c)) {
            count++;
        }
    }
    if (count == 0) {
        count = 1;
    }
    int share = func_001FA1A8(mgr->m_m1838) / count;
    if (share < func_001F9570(out)) {
        return true;
    }
    return false;
}
