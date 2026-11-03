struct Entry_001DC840 {
    unsigned int m0;
    unsigned int m4;
    char m_pad[0x3C - 0x8];
};

extern Entry_001DC840 D_003EC2F8[42];

extern "C" bool func_001E21C0(int index);
extern "C" int func_001E53A0(unsigned int key, int a);

extern "C" int func_001DC840(void* self, unsigned int id)
{
    int i;
    for (i = 0; i < 42; i++) {
        if (D_003EC2F8[i].m0 == id && func_001E21C0(i))
            return i;
    }
    for (i = 0; i < 42; i++) {
        if (D_003EC2F8[i].m4 == id && func_001E21C0(i)) {
            func_001E53A0(0x6D2E270E, 0);
            return i;
        }
    }
    return -1;
}
