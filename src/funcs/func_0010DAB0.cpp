struct Entry_0010DAB0 {
    int m0;
    int m4;
    unsigned short m_nameLen;
    unsigned short m_refs;
};

struct File_0010DAB0 {
    char* m_data;
    int m_key;
    int m_size;
    int m_refs;
};

extern "C" int func_00105520(const char*);
extern "C" Entry_0010DAB0* func_0010D9F8(int);
extern "C" char* func_0010E1E8(const char*, int*, int, int);
extern File_0010DAB0 D_003966F8[200];

char* func_0010DAB0(const char* name)
{
    int key = func_00105520(name);
    Entry_0010DAB0* e = func_0010D9F8(key);
    if (e) {
        e->m_refs++;
        return (char*)((e->m_nameLen + (unsigned int)e + 0x1F) & 0xFFFFFFF0);
    }
    int i;
    for (i = 0; i < 200; i++) {
        if (D_003966F8[i].m_data && D_003966F8[i].m_key == key) {
            D_003966F8[i].m_refs++;
            return D_003966F8[i].m_data;
        }
    }
    File_0010DAB0* slot = 0;
    for (int j = 0; j < 200; j++) {
        if (!D_003966F8[j].m_data) {
            slot = &D_003966F8[j];
            break;
        }
    }
    int size;
    char* data = func_0010E1E8(name, &size, 0, 0);
    slot->m_data = data;
    slot->m_size = size;
    slot->m_key = key;
    slot->m_refs = 1;
    return slot->m_data;
}
