struct Arr_001A0998 {
    int m_pad[3];
    unsigned int m_count;
};

struct Node_001A0998 {
    unsigned char m0;
    unsigned char m_type;
    unsigned char m2;
    unsigned char m3;
    int m_next;
    int m_value;
    Arr_001A0998* mC;
};

extern "C" int func_001A0E08(void* key);
extern "C" Node_001A0998* func_001E6E90(void* list, Node_001A0998* prev);
extern "C" Node_001A0998* func_001E5040(int value);
extern "C" int func_001E9300(Arr_001A0998* arr, unsigned int i);

int func_001A0998(void* key, void* list)
{
    int id = func_001A0E08(key);
    Node_001A0998* node = 0;
    while ((node = func_001E6E90(list, node)) != 0) {
        if (node->m_next) continue;
        Arr_001A0998* arr = 0;
        if (node->m_type == 13) {
            Node_001A0998* ref = func_001E5040(node->m_value);
            if (ref && ref->m2 == 12) {
                arr = ref->mC;
            } else if (node->m_value == id) {
                return 1;
            }
        } else if (node->m_type == 12) {
            arr = (Arr_001A0998*)node->m_value;
        }
        if (!arr) continue;
        for (unsigned int i = 0; i < arr->m_count; i++) {
            if (func_001E9300(arr, i) == id) return 1;
        }
    }
    return 0;
}
