struct Entry_0010DCF8 {
    int m_used;
    int m_key;
    int m_value;
    int mC;
};

extern Entry_0010DCF8 D_003966F8[200];
extern "C" int* func_0010D9F8(int key);

extern "C" int func_0010DCF8(int key)
{
    for (int i = 0; i < 200; i++) {
        if (D_003966F8[i].m_used && D_003966F8[i].m_key == key) {
            return D_003966F8[i].m_value;
        }
    }
    int* p = func_0010D9F8(key);
    if (p) {
        return *p;
    }
    return 0;
}
