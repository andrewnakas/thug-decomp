struct Node_001DEA98 {
    int m_key;
    int m_sub;
    int m8;
    int m_id;
    Node_001DEA98* m_next;
};

struct Entry_001DEA98 {
    char m_data[0x3C];
};

extern Node_001DEA98* D_0038E0AC;
extern Entry_001DEA98 D_003EC304[];

extern "C" int func_001DD678(void* a, int key, int* idx);

extern "C" Entry_001DEA98* func_001DEA98(void* a, int id, int sub)
{
    for (Node_001DEA98* n = D_0038E0AC; n; n = n->m_next) {
        if (n->m_id == id && n->m_sub == sub) {
            int idx;
            if (!func_001DD678(a, n->m_key, &idx))
                return 0;
            return &D_003EC304[idx];
        }
    }
    return 0;
}
