struct Entry_00229C20 {
    int m_key;
    unsigned short* m_data;
};

extern unsigned int D_0038FB68;
extern Entry_00229C20 D_003FD988[];
extern unsigned short D_0038FB70;
extern "C" int func_002297A8(int key);

unsigned short* Find_00229C20(int key, unsigned short* count)
{
    if (D_0038FB68) {
        int i = func_002297A8(key);
        if (D_003FD988[i].m_key == key) {
            unsigned short* p = D_003FD988[i].m_data;
            *count = *p;
            return p + 1;
        }
    }
    *count = 0;
    return &D_0038FB70;
}
