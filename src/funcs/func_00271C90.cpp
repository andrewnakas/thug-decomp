struct Gap_00271C90 {
    char pad[0xC];
    Gap_00271C90* m_prev;
    Gap_00271C90* m_next;
    int pad14;
    char m_name[0x10];
    unsigned int m_28;
    int m_2C;
    unsigned int m_30;
    int m_34;
    int m_38;
};

struct Owner_00271C90 {
    char pad[0x34];
    Gap_00271C90 m_list;
};

struct Self_00271C90 {
    char pad[0x34];
    char m_list[0x18];
    int m_4C;
};

struct Info_00271C90 {
    char pad[0xB8];
    int m_B8;
};

extern "C" void* func_001046B0(int size);
extern "C" Gap_00271C90* func_0026CD40(void* p);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" void func_00104110(char* str, const char* s);

static inline void Append_00271C90(Gap_00271C90* head, Gap_00271C90* node)
{
    node->m_next = head;
    node->m_prev = head->m_prev;
    head->m_prev->m_next = node;
    head->m_prev = node;
}

void func_00271C90(Self_00271C90* self, void* params, Info_00271C90* info)
{
    Gap_00271C90* gap = func_0026CD40(func_001046B0(0x3C));
    Append_00271C90((Gap_00271C90*)self->m_list, gap);
    gap->m_2C = info->m_B8;
    gap->m_34 = 0;
    gap->m_38 = self->m_4C;
    unsigned int type = 0;
    func_001E8398(params, 0x3B442E26, &type, 0);
    gap->m_28 = type;
    const char* name = 0;
    func_001E7C80(params, 0x3EAFA520, &name, 0);
    func_00104110(gap->m_name, name);
    gap->m_30 = 0;
    func_001E8398(params, 0xA26994E6, &gap->m_30, 1);
}
