/* sym: _$_13Base_00270F48 = 0x00184DD8 */
/* sym: _vt$14Owner_00270F48 = 0x00376688 */
/* sym: _vt$14LinkA_00270F48 = 0x003763E0 */
/* sym: _vt$14LinkB_00270F48 = 0x00376398 */
struct Base_00270F48 {
    int m_pad[6];
    virtual void Update();
    virtual ~Base_00270F48();
};

struct LinkA_00270F48 {
    int m0;
    int m4;
    int m8;
    LinkA_00270F48* m_next;
    LinkA_00270F48* m_prev;
    virtual void Fn();
    virtual ~LinkA_00270F48()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct LinkB_00270F48 {
    int m0;
    int m4;
    int m8;
    LinkB_00270F48* m_next;
    LinkB_00270F48* m_prev;
    virtual void Fn();
    virtual ~LinkB_00270F48()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct Owner_00270F48 : Base_00270F48 {
    LinkB_00270F48 m1C;
    LinkA_00270F48 m34;
    virtual void Update();
    virtual ~Owner_00270F48();
};

Owner_00270F48::~Owner_00270F48()
{
}
