struct Filter_00214040 {
    int m_type;
    int m_mode;
    int m_count;
    int m_found;
};

extern "C" void func_00213C50(Filter_00214040* f, int type, int mode);

struct Query_00214040 {
    unsigned int m_name;
    Filter_00214040 m_filter;
    Query_00214040(unsigned int name, int type, int mode)
    {
        m_name = name;
        func_00213C50(&m_filter, type, mode);
    }
};

struct Game_00214040 {
    char pad[0x28];
    void* m_28;
};

extern "C" void* func_001E55B8(unsigned int name, int a);
extern "C" void* func_001E9378(void* table, unsigned int name);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_0022E040(Game_00214040* game);
extern "C" void func_00187900(void* list, bool (*cb)(void*, void*), void* data);
extern "C" bool func_00213B60(void* obj, void* data);
extern "C" int func_00269140(void* p, unsigned int name);
extern "C" void* func_00131E48();
extern "C" void* func_00132FD0(void* mgr, unsigned int name);
extern "C" int func_001350B8(void* p);

extern Game_00214040* D_0038FC78;

int func_00214040(unsigned int name)
{
    Game_00214040* game = D_0038FC78;
    void* params = func_001E9378(func_001E55B8(0xC472ECC5, 0), name);
    unsigned int type = 0;
    func_001E8398(params, 0x12B4E660, &type, 0);
    switch (type) {
    case 0x9E7D469E:
    case 0x5B8AB877:
    case 0xA0DFAC98:
    case 0xE47F1B79:
    case 0xEF59C100:
    case 0x061A741E:
    case 0xB7B3BD86:
    case 0x19B1E241: {
        Query_00214040 q(name, 0, 6);
        q.m_name = name;
        func_00187900(func_0022E040(game), func_00213B60, &q);
        return q.m_filter.m_found != 0;
    }
    case 0xBF4D3536: {
        unsigned int id = 0;
        if (func_001E8398(params, 0xA1DC81F9, &id, 0)) {
            return func_001350B8(func_00132FD0(func_00131E48(), id));
        }
        return 1;
    }
    case 0x30C19600:
    case 0x8E6B02AD:
        return func_00269140(game->m_28, name);
    case 0xE594F0A2:
        return 1;
    }
    return 0;
}
