/* fuzzy: 97.7 */
struct SemaParam_001FD510 {
    int current_count;
    int max_count;
    int init_count;
    int num_wait_threads;
    unsigned int attr;
    unsigned int option;
};

struct Net_001FD510 {
    int m0;
    char m_handlers[0x17F0 - 0x4];
    int m17F0;
    int m17F4;
    int m17F8;
    int m17FC;
    int m1800;
    int m1804;
    char pad1808[0x1820 - 0x1808];
    int m_socket;
    char pad1824[0x1838 - 0x1824];
    void* m1838;
    char pad183C[0x184C - 0x183C];
    int m184C;
    char pad1850[0x227C - 0x1850];
    unsigned int m_flags;
    char pad2280[0x2290 - 0x2280];
    char m_buffer[0x4294 - 0x2290];
    int m_thread_id;
    int m4298;
    int m429C;
    int m42A0;
    int m42A4;
    char m_thread[0x10];
    int m42B8;
    int m42BC;
    void* m42C0;
    char* m42C4;
    int m42C8;
    int m42CC;
    int pad42D0;
    int m42D4;
    int Init();
};

extern "C" int func_00201288(Net_001FD510* net);
extern "C" int func_00326980(int a, int b, int c);
extern "C" int func_00326308(int s, int level, int name, int* value, int len);
extern "C" void func_00200F78(Net_001FD510* net);
extern "C" int func_001F9698(void* p, char* buf);
extern "C" void func_00106038(char* p);
extern "C" int func_0031BCA0(SemaParam_001FD510* p);
extern "C" void func_002E26E0(int a, int b);
extern "C" int func_0031BAC0(int thread, void* arg);
extern "C" void func_001FC070(char* handlers);
extern "C" void func_001FBF60(char* list, int type, void* handler, int a, void* obj, int b);
extern "C" void func_001FE100();
extern "C" void func_001FC6C8();
extern "C" void func_001FCE48();
extern "C" void func_001FC9A0();
extern "C" void func_001FD298();
extern "C" void func_001FD300();

int Net_001FD510::Init()
{
    SemaParam_001FD510 param;
    int on;
    int off;
    if (!func_00201288(this)) {
        off = 0;
        on = 1;
        m_socket = func_00326980(2, 2, 2);
        if (m_socket == -1 || func_00326308(m_socket, 0xFFFF, 0x1014, &on, 4) == -1) {
            goto fail;
        }
        if (m_flags & 1) {
            if (func_00326308(m_socket, 0xFFFF, 0x20, &on, 4) != -1) {
                goto ok;
            }
        } else {
            if (func_00326308(m_socket, 0xFFFF, 0x20, &off, 4) != -1) {
                goto ok;
            }
        }
    fail:
        func_00200F78(this);
        return 0;
    }
ok:
    m42D4 = 0;
    m42CC = 10;
    m42C4 = m_buffer;
    m42C8 = 0x2000;
    m42C0 = (void*)func_001FE100;
    m42B8 = func_001F9698(m1838, m42C4) + 0x110;
    func_00106038(m_thread);
    m_thread_id = m42BC;
    param.init_count = 1;
    param.max_count = 10;
    m429C = func_0031BCA0(&param);
    m42A0 = func_0031BCA0(&param);
    m4298 = func_0031BCA0(&param);
    m42A4 = func_0031BCA0(&param);
    if (!func_00201288(this)) {
        func_002E26E0(m429C, m42A0);
    }
    func_0031BAC0(m_thread_id, this);
    m184C = 0;
    m17F4 = 0;
    m17F0 = 0;
    m17F8 = 0;
    m17FC = 0;
    m1800 = 0;
    m1804 = 0;
    func_001FC070(m_handlers);
    func_001FBF60(m_handlers, 8, (void*)func_001FC6C8, 3, 0, 0x80);
    func_001FBF60(m_handlers, 7, (void*)func_001FCE48, 2, 0, 0x80);
    func_001FBF60(m_handlers, 0xE, (void*)func_001FC9A0, 2, 0, 0x80);
    func_001FBF60(m_handlers, 0xF, (void*)func_001FC9A0, 2, 0, 0x80);
    func_001FBF60(m_handlers, 1, (void*)func_001FD298, 2, 0, 0x80);
    func_001FBF60(m_handlers, 2, (void*)func_001FD300, 2, 0, 0x80);
    return 1;
}
