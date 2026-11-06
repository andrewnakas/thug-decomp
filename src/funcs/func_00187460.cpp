/* sym: _vt$12Obj_00187460 = 0x00361B98 */
extern char D_00361BE0[];

struct Node_00187460 {
    int m0;
    unsigned int m4;
    int m8;
    Node_00187460* m_prev;
    Node_00187460* m_next;
    void* m_vtbl;
    Node_00187460()
    {
        m4 = 0xFFFFFFFF;
        m8 = 0;
        m_prev = this;
        m_next = this;
        m_vtbl = D_00361BE0;
    }
};

class Obj_00187460 {
public:
    int m0;
    Node_00187460 m4;
    int m1C;
    int m20;
    int m24;
    int m28;
    Obj_00187460();
    virtual void F();
};

Obj_00187460::Obj_00187460()
{
    m1C = 0;
    m20 = 0;
    m28 = 0;
}
