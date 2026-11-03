extern char D_003730A0[];

struct Data_002318F0 {
    unsigned char m_obj;
    char m_pad1[3];
    int m_score;
};

struct Msg_002318F0 {
    Data_002318F0* m_data;
    char m_pad4[0x14 - 0x4];
    int m_conn;
    int m18;
    void* m_app;
};

struct Player_002318F0 {
    char m_pad[0x18];
    void* m_skater;
};

struct Score_002318F0 {
    char m_pad[0x24];
    int m_best;
};

extern void* D_00392068;

extern "C" Player_002318F0* func_002A5248(void* self, int conn);
extern "C" unsigned char func_002A7660(void* self);
extern "C" Score_002318F0* func_00203360(void* skater);
extern "C" void* func_0022E358(void* self);
extern "C" bool func_0024F8D8(void* self, const char* name);
extern "C" bool func_0024F4C0(void* self);
extern "C" bool func_0024F328(void* self);
extern "C" bool func_0024F360(void* self);
extern "C" int func_002392B8(Score_002318F0* self);
extern "C" void func_00239198(Score_002318F0* self, int score);

int func_002318F0(Msg_002318F0* msg)
{
    void* net = D_00392068;
    void* app = msg->m_app;
    Player_002318F0* player = func_002A5248(net, msg->m_conn);
    if (!player) {
        return 3;
    }
    Data_002318F0* data = msg->m_data;
    if (func_002A7660(net) != data->m_obj) {
        return 3;
    }
    int score = data->m_score;
    Score_002318F0* s = func_00203360(player->m_skater);
    if (s->m_best < score) {
        s->m_best = score;
    }
    if (func_0024F8D8(func_0022E358(app), D_003730A0)) {
        return 1;
    }
    if (!func_0024F4C0(func_0022E358(app))) {
        return 1;
    }
    if (func_0024F328(func_0022E358(app))) {
        func_00239198(s, func_002392B8(s) + score);
        return 1;
    }
    if (func_0024F360(func_0022E358(app)) && func_002392B8(s) < score) {
        func_00239198(s, score);
    }
    return 1;
}
