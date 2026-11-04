/* sym: _vt$11It_001FE960 = 0x00366B58 */

struct Obj_001FE960 {
    char pad0[0x4C];
    int m_id;
    unsigned short m_sub;
};

struct Node_001FE960 {
    int m0;
    Obj_001FE960* m4;
    int m8;
    Node_001FE960* mC;
    Node_001FE960* Valid() { if (~(int)m4 == 0) return 0; return this; }
    Obj_001FE960* GetData() { return m4; }
};

struct It_001FE960 {
    int m0;
    Node_001FE960* m_cur;

    It_001FE960() { m_cur = 0; }
    virtual void Reset();
    virtual ~It_001FE960() {}
    Obj_001FE960* Next()
    {
        m_cur = m_cur->mC->Valid();
        if (!m_cur) return 0;
        return m_cur->GetData();
    }
    Obj_001FE960* First(Node_001FE960* h)
    {
        m_cur = h;
        return Next();
    }
};

struct Mgr_001FE960 {
    char pad0[0x42D8];
    Node_001FE960 m_list;

    Obj_001FE960* Find(int id, unsigned short sub);
};

Obj_001FE960* Mgr_001FE960::Find(int id, unsigned short sub)
{
    It_001FE960 it;
    for (Obj_001FE960* o = it.First(&m_list); o; o = it.Next()) {
        if (o->m_id == id && o->m_sub == sub) return o;
    }
    return 0;
}
