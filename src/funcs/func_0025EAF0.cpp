struct Viewer_0025EAF0 {
    char m_pad[0x3C];
    int m_loaded;
    unsigned int m_id;
    int m_44[2];
    unsigned int m_script;
    int m_50;
    void Cleanup();
};

extern int D_0038DB38;
extern int D_00388A70;

extern "C" void func_001F0210(unsigned int name, int a, int b, int c, int d);
extern "C" void* func_001D05B0(int mgr, unsigned int id, int a);
extern "C" void func_001D04E0(int mgr, void* p);
extern "C" void func_001363F0();
extern "C" void func_0010B680(int mgr);
extern "C" void func_0025EE80(Viewer_0025EAF0* self);
extern "C" void func_0025AB10(Viewer_0025EAF0* self);

void Viewer_0025EAF0::Cleanup()
{
    func_001F0210(0xE7BC7EFD, 0, 0, 0, 0);
    if (m_loaded) {
        int mgr = D_0038DB38;
        func_001D04E0(mgr, func_001D05B0(mgr, m_id, 1));
        m_loaded = 0;
    }
    if (m_script)
        func_001F0210(m_script, 0, 0, 0, 0);
    func_001F0210(0xF49A8C9C, 0, 0, 0, 0);
    func_001363F0();
    func_0010B680(D_00388A70);
    func_001F0210(0xBCA1791C, m_50, 0, 0, 0);
    func_0025EE80(this);
    func_0025AB10(this);
    func_001F0210(0x15674315, 0, 0, 0, 0);
}
