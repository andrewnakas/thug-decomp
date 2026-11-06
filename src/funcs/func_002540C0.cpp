struct Names_002540C0 {
    const char* p[11];
};

extern "C" void* func_001E93A0(void* p, int i);

struct Arr_002540C0 {
    char pad[0xC];
    unsigned int m_count;
};

struct Slot_002540C0 {
    int m_index;
    unsigned int m_id;
};

extern Names_002540C0 D_00375100;
extern char D_00390830[];
extern char D_00390858[];
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" int func_001E82B8(void* params, const char* name, Arr_002540C0** out, int req);
extern "C" unsigned int func_001E9300(void* self, int index);

struct Obj_002540C0 {
    char pad[0x68];
    Slot_002540C0 m_slots[32];
    void Fn(void* params);
};

void Obj_002540C0::Fn(void* params)
{
    const char* key = D_00390830;
    Names_002540C0 names = D_00375100;
    unsigned int any = func_001F0D78(D_00390858);
    Arr_002540C0* arr;
    if (func_001E82B8(params, key, &arr, 0)) {
        unsigned int i = 0;
        if (arr->m_count) {
            do {
                void* e = func_001E93A0(arr, i);
                unsigned int a = func_001E9300(e, 0);
                unsigned int b = func_001E9300(e, 1);
                for (unsigned int j = 0; j < 11; j++) {
                    if (a == func_001F0D78(names.p[j]) || a == any) {
                        for (int k = 0; k < 32; k++) {
                            if (a == any && m_slots[k].m_id == b) {
                                m_slots[k].m_id = 0;
                            } else if (b == any && m_slots[k].m_index == j) {
                                m_slots[k].m_id = 0;
                            } else if (m_slots[k].m_id == 0) {
                                m_slots[k].m_index = j;
                                m_slots[k].m_id = b;
                                break;
                            }
                        }
                        break;
                    }
                }
                i++;
            } while (i < arr->m_count);
        }
    }
}
