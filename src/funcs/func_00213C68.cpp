struct Filter_00213C68 {
    int m_type;
    int m_mode;
    int m_count;
    int m_found;
};

struct Query_00213C68 {
    unsigned int m_name;
    Filter_00213C68 m_filter;
};

extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" void func_00213C50(Filter_00213C68* f, int type, int mode);
extern "C" void* func_0022E040(void* game);
extern "C" void func_00187900(void* list, bool (*cb)(void*, void*), void* data);
extern "C" unsigned short* func_00229C98(const char* names, unsigned short* count);
extern "C" bool func_00213B30(void* obj, void* data);
extern "C" bool func_00213B60(void* obj, void* data);

extern void* D_0038FC78;

int Query_00213C68_Run(void* params, void* script, int mode)
{
    Query_00213C68 q;
    int type = 0;
    if (mode == 5) {
        func_001E8398(params, 0, &type, 0);
    } else {
        func_001E7DE8(params, 0, &type, 0);
    }
    if (!func_001E8708(params, 0x2E7D5EE7)) {
        func_001E8708(params, 0xBCEB479A);
    }
    int name;
    if (func_001E8398(params, 0xA1DC81F9, &name, 0)) {
        q.m_name = name;
        func_00213C50(&q.m_filter, type, mode);
        func_00187900(func_0022E040(D_0038FC78), func_00213B30, &q);
        return q.m_filter.m_count;
    }
    const char* names;
    if (func_001E8870(params, 0x6C4E7971, &names, 0)) {
        unsigned short count = 0;
        unsigned short* list = func_00229C98(names, &count);
        void* game = D_0038FC78;
        func_00213C50(&q.m_filter, type, mode);
        for (int i = 0; i < count; i++) {
            q.m_name = list[i];
            func_00187900(func_0022E040(game), func_00213B60, &q);
        }
        return q.m_filter.m_count;
    }
    return 0;
}
