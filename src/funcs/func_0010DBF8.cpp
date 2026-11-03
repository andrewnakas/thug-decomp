struct Entry_0010DBF8 {
    int m0;
    int m4;
    unsigned short m_nameLen;
    unsigned short m_refs;
};

struct File_0010DBF8 {
    char* m_data;
    int m_key;
    int m_size;
    int m_refs;
};

extern "C" void func_0010BEB8(char*);
extern "C" Entry_0010DBF8* func_0010D9F8(int);
extern File_0010DBF8 D_003966F8[200];

void func_0010DBF8(int key)
{
    for (int i = 0; i < 200; i++) {
        if (D_003966F8[i].m_data && D_003966F8[i].m_key == key) {
            if (D_003966F8[i].m_refs == 0 || --D_003966F8[i].m_refs == 0) {
                func_0010BEB8(D_003966F8[i].m_data);
                D_003966F8[i].m_data = 0;
                D_003966F8[i].m_size = 0;
                D_003966F8[i].m_key = 0;
                D_003966F8[i].m_refs = 0;
            }
        }
    }
    Entry_0010DBF8* e = func_0010D9F8(key);
    if (e && e->m_refs)
        e->m_refs--;
}
