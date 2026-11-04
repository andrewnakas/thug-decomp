struct Node_0025F9D0 {
    char m_pad[0xC];
    Node_0025F9D0* m_next;
    Node_0025F9D0* m_prev;
};

class Screen_0025F9D0 : public Node_0025F9D0 {
public:
    virtual ~Screen_0025F9D0();
    virtual bool Init(int arg);
};

struct Mgr_0025F9D0 {
    char m_pad[0x48];
    Node_0025F9D0 m_list;
    char m_pad5c[0x124 - 0x5C];
    int m_124;
    bool Push(int owner, int arg, unsigned int type);
};

extern "C" int func_0025F0F0(Mgr_0025F9D0* self);
extern "C" Screen_0025F9D0* func_0025F128(Mgr_0025F9D0* self, int i);
extern "C" unsigned int func_0025AB70(Screen_0025F9D0* s);
extern "C" void func_0025F460(Mgr_0025F9D0* self);
extern "C" void func_00137FD0(int a, int b, int c);
extern "C" void* func_001046B0(int size);
extern "C" Screen_0025F9D0* func_0025E710(void* mem);
extern "C" Screen_0025F9D0* func_0025AB80(void* mem);
extern "C" Screen_0025F9D0* func_0025B310(void* mem);
extern "C" void func_0025AB60(Screen_0025F9D0* s, int owner);
extern "C" void* func_0025F3F0(Mgr_0025F9D0* self);
extern "C" void func_0013B040(int a, void* b);

bool Mgr_0025F9D0::Push(int owner, int arg, unsigned int type)
{
    Screen_0025F9D0* s = 0;
    int saved = m_124;
    m_124 = 0;
    switch (type) {
    case 0xF5012F52:
        if (func_0025F0F0(this)) {
            for (int i = 0; i < func_0025F0F0(this); i++) {
                func_0025AB70(func_0025F128(this, i));
            }
            func_0025F460(this);
            m_124 = 0;
        }
        func_00137FD0(0, 1, 0);
        s = func_0025E710(func_001046B0(0x68));
        break;
    case 0x12743EDB:
        s = func_0025AB80(func_001046B0(0x78));
        break;
    case 0x66B7DD11:
        s = func_0025B310(func_001046B0(0xC0));
        break;
    }
    func_0025AB60(s, owner);
    if (!s->Init(arg)) {
        delete s;
        m_124 = saved;
        return false;
    }
    Node_0025F9D0* head = &m_list;
    s->m_prev = head->m_prev;
    s->m_next = head;
    head->m_prev->m_next = s;
    head->m_prev = s;
    if (func_0025F0F0(this) == 1) {
        func_0013B040(0, func_0025F3F0(this));
    }
    return true;
}
