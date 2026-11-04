struct Array_001DBA90 {
    char m_pad[0xC];
    int m_size;
    int GetSize() const { return m_size; }
};

extern "C" int func_001E8180(void* s, unsigned int key, int* out, int flag);
extern "C" int func_001E8248(void* s, unsigned int key, Array_001DBA90** out, int flag);
extern "C" int func_001E9378(Array_001DBA90* a, int i);
extern "C" int func_001E7DE8(int s, unsigned int key, int* out, int flag);
extern "C" int func_00100030(int n);

extern "C" int func_001DBA90(void* params)
{
    int value;
    if (func_001E8180(params, 0x25F654C8, &value, 0)) {
        return value;
    }
    Array_001DBA90* list;
    func_001E8248(params, 0x25F654C8, &list, 1);
    int total = 0;
    int i = list->GetSize();
    while (i--) {
        value = func_001E9378(list, i);
        int weight;
        func_001E7DE8(value, 0xDBC4C4DB, &weight, 1);
        total += weight;
    }
    int pick = func_00100030(total);
    i = list->GetSize();
    while (i--) {
        value = func_001E9378(list, i);
        int weight;
        func_001E7DE8(value, 0xDBC4C4DB, &weight, 1);
        pick -= weight;
        if (pick < 0) {
            return value;
        }
    }
    return 0;
}
