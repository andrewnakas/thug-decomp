/* sym: _vt$11It_002010D0 = 0x00366B58 */

struct It_002010D0 {
    void* m_cur;
    int m_4;

    It_002010D0() { m_4 = 0; }
    virtual void Reset();
    virtual ~It_002010D0() {}
};

struct Mgr_002010D0;
extern "C" void* func_00200EC0(Mgr_002010D0* self, It_002010D0* it);
extern "C" void* func_00200EF8(Mgr_002010D0* self, It_002010D0* it);
extern "C" void func_002027F8(void* conn, int a);
extern "C" int func_00201288(Mgr_002010D0* self);
extern "C" void func_00200F88(Mgr_002010D0* self);
extern "C" void func_0031BCE0(int sema);
extern "C" void func_0031BCC0(int sema);

struct Mgr_002010D0 {
    int m_count;
    char pad4[0x4290 - 0x4];
    int m_4290;
    int m_4294;
    int m_4298;

    void Process(int skip);
};

void Mgr_002010D0::Process(int skip)
{
    It_002010D0 it;
    if (!skip) {
        m_count++;
        for (void* c = func_00200EC0(this, &it); c; c = func_00200EF8(this, &it)) {
            func_002027F8(c, 1);
        }
    }
    if (!func_00201288(this) && m_4290) func_0031BCE0(m_4298);
    func_00200F88(this);
    if (!func_00201288(this) && m_4290) func_0031BCC0(m_4298);
}
