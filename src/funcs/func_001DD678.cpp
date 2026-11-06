struct Entry_001DD678 {
    int m_key;
    char m_pad4[0x3C - 4];
};

extern Entry_001DD678 D_003EC2F8[];

extern "C" int func_001DC418(int a);
extern "C" int func_001E21C0(int idx);

extern "C" int func_001DD678(int a, int key, int* out)
{
    if (func_001DC418(a))
        return 0;
    if (key) {
        for (int i = 0; i < 42; i++) {
            if (D_003EC2F8[i].m_key == key) {
                if (!func_001E21C0(i))
                    return 0;
                if (out)
                    *out = i;
                return 1;
            }
        }
    }
    return 0;
}
