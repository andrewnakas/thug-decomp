/* fuzzy: 87.1 */
/* sym: _vt$12Obj_00183CF8 = 0x00361918 */
/* sym: _vt$13Link_00183CF8 = 0x0035D358 */
/* sym: __13List_00183CF8 = 0x00183BF0 */

extern int D_0038C6D4;
extern int D_0038C6D8;

class Link_00183CF8 {
public:
    int m0;
    void* m_owner;
    int m8;
    Link_00183CF8* m_prev;
    Link_00183CF8* m_next;

    Link_00183CF8(void* owner)
    {
        m_owner = owner;
        m8 = 0;
        m_prev = this;
        m_next = this;
    }
    virtual ~Link_00183CF8();
};

class List_00183CF8 {
public:
    int m0;
    void* m_head;

    List_00183CF8();
    virtual ~List_00183CF8();
};

class Obj_00183CF8 : public List_00183CF8 {
public:
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    Link_00183CF8 m_link;
    int m44;

    Obj_00183CF8();
    virtual ~Obj_00183CF8();
};

Obj_00183CF8::Obj_00183CF8() : m_link(this)
{
    m24 = 0;
    m18 = D_0038C6D4;
    m1C = D_0038C6D8;
    m14 = 0;
    m10 = 0;
    mC = 0;
    m44 = 0;
    m20 = 0;
}
