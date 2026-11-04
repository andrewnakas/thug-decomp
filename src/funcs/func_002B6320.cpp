struct Node_002B6320 {
    char pad0[0x28];
    Node_002B6320* m28;
};

struct List_002B6320 {
    unsigned char m0;
    unsigned char m1;
    char pad2[6];
    Node_002B6320* m8;
    char padC[4];
    unsigned short m10;
    int Count();
};

int List_002B6320::Count()
{
    if (m1)
        return m10;
    int n = 0;
    for (Node_002B6320* p = m8; p; p = p->m28)
        n++;
    return n - 1;
}
