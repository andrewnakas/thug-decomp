/* sym: _vt$11It_001FEA20 = 0x00366B58 */

struct Obj_001FEA20 {
    char pad0[0x48];
    int m_id;
};

struct Node_001FEA20 {
    int m0;
    Obj_001FEA20* m4;
    int m8;
    Node_001FEA20* mC;
    Node_001FEA20* Valid() { if (~(int)m4 == 0) return 0; return this; }
    Obj_001FEA20* GetData() { return m4; }
};

struct It_001FEA20 {
    int m0;
    Node_001FEA20* m_cur;

    It_001FEA20() { m_cur = 0; }
    virtual void Reset();
    virtual ~It_001FEA20() {}
    Obj_001FEA20* Next()
    {
        m_cur = m_cur->mC->Valid();
        if (!m_cur) return 0;
        return m_cur->GetData();
    }
    Obj_001FEA20* First(Node_001FEA20* h)
    {
        m_cur = h;
        return Next();
    }
};

struct Mgr_001FEA20 {
    char pad0[0x42D8];
    Node_001FEA20 m_list;

    Obj_001FEA20* Find(int id);
};

Obj_001FEA20* Mgr_001FEA20::Find(int id)
{
    It_001FEA20 it;
    for (Obj_001FEA20* o = it.First(&m_list); o; o = it.Next()) {
        if (o->m_id == id) return o;
    }
    return 0;
}
