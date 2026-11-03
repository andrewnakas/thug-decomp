struct Data_00242E58 {
    unsigned char m_player;
    int m_goal;
    int pad[2];
};

struct Msg_00242E58 {
    unsigned char m_id;
    unsigned char m1;
    unsigned short m_length;
    void* m_data;
    char pad8[0x20 - 0x8];
};

struct Goal_00242E58 {
    char pad0[0x30];
    int* m30;
};

extern "C" void* func_00240850();
extern "C" bool func_001E8398(void* s, unsigned int name, unsigned int* out, int required);
extern "C" Goal_00242E58* func_0023BAD8(void* mgr, unsigned int name, int a);
extern "C" bool func_00246C60(Goal_00242E58* g);
extern "C" void* func_002A39E0(void* net, int a);
extern "C" void func_001FA800(Msg_00242E58* msg);
extern "C" void func_002A56E0(void* net);
extern "C" unsigned char func_002A7660(void* net);
extern "C" int func_00246258(Goal_00242E58* g);
extern "C" void func_00200C00(void* client, Msg_00242E58* msg);

extern void* D_00392068;

bool Cmd_SendGoal_00242E58(void* params, void* script)
{
    void* net = D_00392068;
    void* mgr = func_00240850();
    unsigned int name;
    func_001E8398(params, 0xA1DC81F9, &name, 1);
    Goal_00242E58* goal = func_0023BAD8(mgr, name, 1);
    if (func_00246C60(goal) || *goal->m30 != 0) {
        return true;
    }
    Data_00242E58 data;
    Msg_00242E58 msg;
    void* client = func_002A39E0(net, 0);
    func_001FA800(&msg);
    func_002A56E0(net);
    data.m_player = func_002A7660(net);
    data.m_goal = func_00246258(goal);
    msg.m_length = 8;
    msg.m_data = &data;
    msg.m_id = 0x6F;
    func_00200C00(client, &msg);
    return true;
}
