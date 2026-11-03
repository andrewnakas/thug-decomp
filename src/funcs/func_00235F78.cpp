struct MsgDesc_00235F78 {
    unsigned char m_id;
    char pad1;
    unsigned short m_length;
    void* m_data;
    int m8;
    int m_priority;
    unsigned char m_queue;
    char pad11[0xF];
};

struct Data_00235F78 {
    int m_num;
    unsigned int m_ids[35];
};

struct Goal_00235F78 {
    char pad[0x24];
    void* m24;
};

extern void* D_00392068;

extern "C" MsgDesc_00235F78* func_001FA800(MsgDesc_00235F78* self);
extern "C" bool func_00263BD8(void* self, unsigned int name);
extern "C" void* func_002A39D8(void* self, int id);
extern "C" int func_002B3080(int id);
extern "C" void func_001FF970(void* self, int conn, MsgDesc_00235F78* msg);

void func_00235F78(Goal_00235F78* self, int player)
{
    Data_00235F78 data;
    MsgDesc_00235F78 msg;

    void* game = D_00392068;
    func_001FA800(&msg);
    data.m_num = 0;
    if (func_00263BD8(self->m24, 0xEEFECF1B))
        data.m_ids[data.m_num++] = 0xEEFECF1B;
    if (func_00263BD8(self->m24, 0xB38341C9))
        data.m_ids[data.m_num++] = 0xB38341C9;
    if (func_00263BD8(self->m24, 0xCD09E062))
        data.m_ids[data.m_num++] = 0xCD09E062;
    if (func_00263BD8(self->m24, 0x69A1CE96))
        data.m_ids[data.m_num++] = 0x69A1CE96;
    if (func_00263BD8(self->m24, 0xEEFECF1B))
        data.m_ids[data.m_num++] = 0xEEFECF1B;
    if (func_00263BD8(self->m24, 0x6B0F24BC))
        data.m_ids[data.m_num++] = 0x6B0F24BC;
    if (func_00263BD8(self->m24, 0x520A66EF))
        data.m_ids[data.m_num++] = 0x520A66EF;
    if (func_00263BD8(self->m24, 0xEBA89179))
        data.m_ids[data.m_num++] = 0xEBA89179;
    if (func_00263BD8(self->m24, 0xC4FFC672))
        data.m_ids[data.m_num++] = 0xC4FFC672;
    if (func_00263BD8(self->m24, 0xD5982173))
        data.m_ids[data.m_num++] = 0xD5982173;
    msg.m_id = 0x82;
    msg.m_priority = 2;
    int queue = 8;
    msg.m_queue = queue;
    msg.m_length = data.m_num * 4 + 4;
    msg.m_data = &data;
    func_001FF970(func_002A39D8(game, queue), func_002B3080(player), &msg);
}
