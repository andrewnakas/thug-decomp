/* sym: _vt$12Obj_00183D80 = 0x00361918 */
/* sym: _vt$13Link_00183D80 = 0x0035D358 */
/* sym: _$_13List_00183D80 = 0x00183C08 */
/* sym: _$_14Sound_00183D80 = 0x001E6AE8 */
/* sym: _$_14Track_00183D80 = 0x001EE4D8 */

extern "C" void func_001F0DE8(void* obj);

class Link_00183D80 {
public:
    int m0;
    void* m_owner;
    int m8;
    Link_00183D80* m_prev;
    Link_00183D80* m_next;

    virtual void Key();
    virtual ~Link_00183D80()
    {
        m_next->m_prev = m_prev;
        m_prev->m_next = m_next;
        m_prev = this;
        m_next = this;
    }
};

class List_00183D80 {
public:
    int m0;
    void* m_head;

    virtual ~List_00183D80();
};

class Sound_00183D80 {
public:
    ~Sound_00183D80();
};

class Track_00183D80 {
public:
    ~Track_00183D80();
};

class Child_00183D80 {
public:
    char pad[0x2C];
    virtual void V1();
    virtual void V2();
    virtual void Release(void* owner);
};

class Obj_00183D80 : public List_00183D80 {
public:
    int mC;
    Child_00183D80* m_child;
    Track_00183D80* m_track;
    int m18;
    int m1C;
    int m20;
    Sound_00183D80* m_sound;
    int m28;
    Link_00183D80 m_link;
    int m44;

    virtual void Key();
    virtual ~Obj_00183D80();
};

Obj_00183D80::~Obj_00183D80()
{
    if (m_sound) {
        delete m_sound;
    }
    if (m_child) {
        m_child->Release(this);
    }
    if (m_track) {
        delete m_track;
        m_track = 0;
    }
    func_001F0DE8(this);
}
