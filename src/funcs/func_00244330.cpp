/* sym: _$_13Link_00244330 = 0x00243D88 */
struct Link_00244330 {
    int m_id;
    Link_00244330* m_next;
    ~Link_00244330();
};

struct Obj_00244330 {
    void Free(Link_00244330* p);
};

void Obj_00244330::Free(Link_00244330* p)
{
    while (p) {
        Link_00244330* next = p->m_next;
        delete p;
        p = next;
    }
}
