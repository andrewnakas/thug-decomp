struct Map_0010B0A8 {
    int m0;
    int a[0x20];
    int m84;
    int Find(int key);
};

int Map_0010B0A8::Find(int key)
{
    for (int i = 0; i < m84 - 1; i++) {
        if (a[i] == key) return a[i + 1];
    }
    return 0;
}
