struct Array_00239D68 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

struct Entry_00239D68 {
    int m0;
    int m4;
    unsigned int m_type;
    int mC;
    unsigned int m_name;
    int m14;
    unsigned int m_flags;
    char m_active;
};

struct Player_00239D68 {
    void* m_params;
};

struct Players_00239D68 {
    char m_pad[0x248];
    Player_00239D68* m_players[1];
};

struct List_00239D68;

struct Self_00239D68 {
    char m_pad[0x44];
    char m_list[0x14];
    int m_count;
};

extern void* D_0038FC78;

extern "C" void* func_0022E368(void* game, int a);
extern "C" void* func_00262330(void* info, unsigned int name);
extern "C" void* func_00262358(void* info);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8248(void* params, unsigned int name, Array_00239D68** out, int required);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E7D70(void* params, unsigned int name, const char** out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" void* func_001E9378(Array_00239D68* array, int index);
extern "C" void* func_001E5548(unsigned int name, int required);
extern "C" Array_00239D68* func_001E55B8(unsigned int name, int required);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" Players_00239D68* func_0022DD38(void* game);
extern "C" Entry_00239D68* func_0023AFE8(void* list, int index);

static inline int GetIndex_00239D68(unsigned int id)
{
    void* info = func_0022E368(D_0038FC78, 0);
    void* params = func_00262330(info, 0xD544AA2D);
    int index = -1;
    if (!func_001E7DE8(params, id, &index, 0)) {
        Array_00239D68* list;
        func_001E8248(func_00262358(info), 0, &list, 1);
        int num = list->m_size;
        for (int i = 0; i < num; i++) {
            void* entry = func_001E9378(list, i);
            int active = 0;
            func_001E7DE8(entry, 0xB56A8816, &active, 0);
            if (active) {
                unsigned int entry_id;
                func_001E8398(entry, 0xA92A2280, &entry_id, 1);
                if (entry_id == id) {
                    unsigned int value;
                    func_001E8398(entry, 0x5B077CE1, &value, 1);
                    index = value;
                    break;
                }
            }
        }
    }
    return index;
}



extern "C" int func_00239930(Self_00239D68* self, int index, unsigned int name, int a, int b);

int func_00239D68(Self_00239D68* self, unsigned int id, int a, int b, int level)
{
    int index = self->m_count;
    for (;;) {
        if (index <= 0) {
            return 0;
        }
        index--;
        if (func_0023AFE8(self->m_list, index)->m_active) {
            break;
        }
    }
    void* info = func_0022E368(D_0038FC78, 0);
    void* params = func_00262330(info, 0xD544AA2D);
    unsigned int script = 0;
    if (!func_001E8398(params, id, &script, 0)) {
        Array_00239D68* list;
        func_001E8248(func_00262358(info), 0, &list, 1);
        int num = list->m_size;
        for (int i = 0; i < num; i++) {
            void* entry = func_001E9378(list, i);
            unsigned int entry_id;
            func_001E8398(entry, 0xA92A2280, &entry_id, 1);
            if (entry_id == id) {
                func_001E8398(entry, 0x5B077CE1, &script, 1);
                break;
            }
        }
    }
    unsigned int name;
    if (!script) {
        name = 0;
    } else {
        void* node;
        func_001E8180(func_001E5548(script, 1), 0x7031F10C, &node, 1);
        for (int i = level; i > 1; ) {
            i--;
            unsigned int parent;
            func_001E8398(node, 0x6E855102, &parent, 0);
            func_001E8180(func_001E9378(func_001E55B8(parent, 1), 0), 0x7031F10C, &node, 1);
        }
        const char* text;
        func_001E7D70(node, 0xA1DC81F9, &text, 1);
        name = func_001F0D78(text);
    }
    if (!name) {
        int player = GetIndex_00239D68(id);
        if (player == -1) {
            return 0;
        }
        Players_00239D68* players = func_0022DD38(D_0038FC78);
        if (players) {
            const char* text;
            func_001E7C80(players->m_players[player]->m_params, 0xA1DC81F9, &text, 1);
            name = func_001F0D78(text);
        }
    }
    return func_00239930(self, index, name, a, b);
}
