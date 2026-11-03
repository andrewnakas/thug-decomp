extern char D_00375DF8[];

struct Array_00264788 {
    char pad[0xC];
    int m_size;
};

struct List_00264788 {
    int pad0;
    unsigned int m_ids[0x100];
    int m_count;
};

extern "C" Array_00264788* func_001E55F8(const char* name, int create);
extern "C" unsigned int func_001E9300(Array_00264788* arr, int i);
extern "C" int func_00264858(List_00264788* list, unsigned int id);

void func_00264788(List_00264788* list)
{
    list->m_count = 0;
    Array_00264788* arr = func_001E55F8(D_00375DF8, 0);
    for (int i = 0; i < arr->m_size; i++) {
        unsigned int id = func_001E9300(arr, i);
        if (func_00264858(list, id) == -1) {
            list->m_ids[list->m_count] = id;
            list->m_count++;
        }
    }
}
