struct C_00264858 {
    int m0;
    int m4[256];
    int m404;
    int Find(int x);
};

int C_00264858::Find(int x)
{
    for (int i = 0; i < m404; i++) {
        if (x == m4[i]) return i;
    }
    return -1;
}
