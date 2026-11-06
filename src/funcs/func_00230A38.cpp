struct Entry_00230A38 {
    char pad[0x80];
    unsigned short m_80;
    char pad82[0x90 - 0x82];
};

struct Hist_00230A38 {
    char pad[0x1C];
    int m_count;
    Entry_00230A38 m_entries[20];
};

struct Info_00230A38 {
    char pad[0x18];
    int m_index;
    char pad1C[0x2DC - 0x1C];
    Hist_00230A38* m_2DC;
};

struct Player_00230A38 {
    char pad[0x18];
    Info_00230A38* m_info;
};

struct Self_00230A38 {
    char pad[0x4C];
    unsigned int m_ids[8];
};

struct Msg_00230A38 {
    char pad[0x18];
    unsigned short m_id;
};

struct Handler_00230A38 {
    bool Check(Self_00230A38* self, Msg_00230A38* msg);
};

extern void* D_00392068;
extern "C" Player_00230A38* func_002A52F0(void* a, int id);

bool Handler_00230A38::Check(Self_00230A38* self, Msg_00230A38* msg)
{
    Player_00230A38* p = func_002A52F0(D_00392068, msg->m_id);
    if (!p) {
        return false;
    }
    if (p == (Player_00230A38*)self) {
        return false;
    }
    Info_00230A38* info = p->m_info;
    Hist_00230A38* h = info->m_2DC;
    if (!h->m_count) {
        return false;
    }
    unsigned int id = self->m_ids[info->m_index];
    return h->m_entries[(h->m_count - 1) % 20].m_80 != id;
}
