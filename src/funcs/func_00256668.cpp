extern char D_003753D8[];

extern "C" void func_001F0370(const char* name, void* params, void* obj, int a);
extern "C" void* func_0022BFE0();
extern "C" void func_0022BFE8(void* p, int flag);



struct Viewer_00256668 {
    char m_pad[0x168];
    union {
        unsigned int m_buttons;
        unsigned char m_bytes[4];
    };
    int m_16C;
    float m_level;
    int m_174;
    bool m_showPanel;
    void SetLevel(float level);
    void Step(int dir);
    void Refresh();
    void HandleInput();
};

extern "C" void func_00255AD0(Viewer_00256668* self, float level);
extern "C" void func_00255C10(Viewer_00256668* self, int dir);
extern "C" void func_002561B0(Viewer_00256668* self);

void Viewer_00256668::HandleInput()
{
    if (m_buttons & 0x1000) {
        m_showPanel = !m_showPanel;
        func_001F0370(D_003753D8, 0, 0, 0);
    }
    if (m_buttons & 0x40)
        func_00255AD0(this, m_level + 0.25f);
    unsigned long t = m_bytes[0];
    if (t >> 7)
        func_00255AD0(this, m_level - 0.25f);
    if (m_bytes[1] & 1)
        func_00255C10(this, 1);
    if (m_buttons & 0x200)
        func_00255C10(this, 0);
    if (m_buttons & 0x20000) {
        void* p = func_0022BFE0();
        if (p)
            func_0022BFE8(p, 0x4000);
    }
    if (m_buttons & 0x2000) {
        void* p = func_0022BFE0();
        if (p)
            func_0022BFE8(p, 2);
    }
    if (m_buttons & 0x4000) {
        void* p = func_0022BFE0();
        if (p)
            func_0022BFE8(p, 4);
    }
    unsigned long t2 = m_bytes[1];
    if (t2 >> 7) {
        void* p = func_0022BFE0();
        if (p)
            func_0022BFE8(p, 0x10000);
    }
    if (m_buttons & 0x10000) {
        void* p = func_0022BFE0();
        if (p)
            func_0022BFE8(p, 0x20000);
    }
    func_002561B0(this);
    m_buttons = 0;
}
