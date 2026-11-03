struct Array_001DBEA8 {
    char m_pad[0xC];
    unsigned int m_size;
    unsigned int GetSize() const { return m_size; }
};

extern "C" unsigned int func_001DB7A8(void* name);
extern "C" int func_001E8180(void* s, unsigned int key, unsigned int* out, int flag);
extern "C" int func_001E8248(void* s, unsigned int key, Array_001DBEA8** out, int flag);
extern "C" void* func_001E9378(Array_001DBEA8* a, unsigned int i);
extern "C" void func_001DBE70(unsigned int name);

extern "C" void func_001DBEA8(void* params, void* name)
{
    unsigned int key = func_001DB7A8(name);
    unsigned int value;
    if (func_001E8180(params, key, &value, 0)) {
        func_001DBE70(value);
        return;
    }
    Array_001DBEA8* list;
    func_001E8248(params, key, &list, 1);
    unsigned int i = 0;
    while (i < list->GetSize()) {
        void* entry = func_001E9378(list, i);
        if (func_001E8180(entry, 0x25F654C8, &value, 0)) {
            func_001DBE70(value);
            i++;
        } else {
            Array_001DBEA8* sub;
            func_001E8248(entry, 0x25F654C8, &sub, 1);
            i++;
            for (unsigned int j = 0; j < sub->GetSize(); j++) {
                value = (unsigned int)func_001E9378(sub, j);
                func_001DBE70(value);
            }
        }
    }
}
