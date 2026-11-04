typedef int (*Handler_00235878)(void* msg);

extern "C" int func_00234688(void* msg);
extern "C" int func_00234CF0(void* msg);
extern "C" int func_00232D00(void* msg);
extern "C" int func_00232C60(void* msg);
extern "C" int func_00233788(void* msg);
extern "C" int func_00233808(void* msg);
extern "C" int func_002338B8(void* msg);
extern "C" int func_00234600(void* msg);
extern "C" int func_00234538(void* msg);
extern "C" int func_002345C0(void* msg);
extern "C" int func_00233EF0(void* msg);
extern "C" int func_00231FC0(void* msg);
extern "C" int func_002325D8(void* msg);
extern "C" int func_00232688(void* msg);
extern "C" int func_00233908(void* msg);
extern "C" int func_00233A60(void* msg);
extern "C" int func_00233D30(void* msg);
extern "C" int func_00233B28(void* msg);
extern "C" int func_00232B80(void* msg);
extern "C" int func_00232898(void* msg);
extern "C" int func_00232B28(void* msg);
extern "C" int func_0023AB80(void* msg);
extern "C" int func_00279978(void* msg);
extern "C" int func_002795B0(void* msg);
extern "C" int func_002738E8(void* msg);
extern "C" void* func_001FBF60(void* disp, int id, Handler_00235878 h, int flags, void* data, int mask);

struct Skater_00235878 {
    char pad[0x31C];
    int m_local;
};

extern "C" Skater_00235878* func_0022DE70(void* mgr, unsigned int i);
extern "C" int func_002041F8(Skater_00235878* s);

struct Server_00235878 {
    int pad;
    char m_disp[1];
};

static inline void AddSkaterHandlers_00235878(Server_00235878* server, void* mgr, int conn)
{
    for (unsigned int i = 0; i < 8; i++) {
        Skater_00235878* sk = func_0022DE70(mgr, i);
        if (sk && sk->m_local && func_002041F8(sk) == conn) {
            func_001FBF60(server->m_disp, 0x3B, func_0023AB80, 0, sk, 0x80);
            func_001FBF60(server->m_disp, 0x44, func_00279978, 0, sk, 0x80);
            func_001FBF60(server->m_disp, 0x43, func_00279978, 0, sk, 0x80);
            func_001FBF60(server->m_disp, 0x85, func_002795B0, 0, sk, 0x80);
            func_001FBF60(server->m_disp, 0x84, func_002795B0, 0, sk, 0x80);
            func_001FBF60(server->m_disp, 0x4B, func_002738E8, 0, sk, 0x80);
        }
    }
}

void func_00235878(void* mgr, Server_00235878* server, int conn)
{
    void* disp = server->m_disp;
    func_001FBF60(disp, 0x33, func_00234688, 0, mgr, 0x80);
    func_001FBF60(disp, 0x23, func_00234CF0, 3, mgr, 0x80);
    func_001FBF60(disp, 0x29, func_00232D00, 0, mgr, 0x80);
    func_001FBF60(disp, 0x7F, func_00232C60, 0, mgr, 0x80);
    func_001FBF60(disp, 0x2B, func_00232D00, 0, mgr, 0x80);
    func_001FBF60(disp, 0x76, func_00232D00, 0, mgr, 0x80);
    func_001FBF60(disp, 0x8C, func_00232D00, 0, mgr, 0x80);
    func_001FBF60(disp, 0x77, func_00232D00, 0, mgr, 0x80);
    func_001FBF60(disp, 0x78, func_00232D00, 0, mgr, 0x80);
    func_001FBF60(disp, 0x2A, func_00232D00, 0, mgr, 0x80);
    func_001FBF60(disp, 0x2C, func_00232D00, 0, mgr, 0xFF);
    func_001FBF60(disp, 0x2C, func_00233788, 0, mgr, 0x80);
    func_001FBF60(disp, 0x3C, func_00232D00, 0, mgr, 0x80);
    func_001FBF60(disp, 0x3D, func_00232D00, 0, mgr, 0x80);
    func_001FBF60(disp, 0x3E, func_00232D00, 0, mgr, 0x80);
    func_001FBF60(disp, 0x41, func_00232D00, 0, mgr, 0x80);
    func_001FBF60(disp, 0x2D, func_00233808, 2, mgr, 0x80);
    func_001FBF60(disp, 0x32, func_002338B8, 2, mgr, 0x80);
    func_001FBF60(disp, 0x35, func_00234600, 0, mgr, 0x80);
    func_001FBF60(disp, 0x36, func_00234600, 0, mgr, 0x80);
    func_001FBF60(disp, 0x37, func_00234538, 0, mgr, 0x80);
    func_001FBF60(disp, 0x38, func_00234538, 0, mgr, 0x80);
    func_001FBF60(disp, 0x39, func_002345C0, 0, mgr, 0x80);
    func_001FBF60(disp, 0x3A, func_002345C0, 0, mgr, 0x80);
    func_001FBF60(disp, 0x40, func_00233EF0, 2, mgr, 0x80);
    func_001FBF60(disp, 0x46, func_00231FC0, 0, mgr, 0x80);
    func_001FBF60(disp, 0x48, func_002325D8, 2, mgr, 0x80);
    func_001FBF60(disp, 0x49, func_00232688, 2, mgr, 0x80);
    func_001FBF60(disp, 0x51, func_00233908, 2, mgr, 0x80);
    func_001FBF60(disp, 0x56, func_00233908, 2, mgr, 0x80);
    func_001FBF60(disp, 0x5B, func_00233A60, 0, mgr, 0x80);
    func_001FBF60(disp, 0x5C, func_00233D30, 0, mgr, 0x80);
    func_001FBF60(disp, 0x7E, func_00233B28, 0, mgr, 0x80);
    func_001FBF60(disp, 0x82, func_00232B80, 0, mgr, 0x80);
    func_001FBF60(disp, 0x83, func_00232898, 0, mgr, 0x80);
    func_001FBF60(disp, 0x89, func_00232B28, 0, mgr, 0x80);
    AddSkaterHandlers_00235878(server, mgr, conn);
}
