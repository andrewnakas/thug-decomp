struct Node_001EC910 {
    int m0;
    int m4;
    char pad8[0x5C - 0x8];
    Node_001EC910* m5C;
};
extern Node_001EC910* D_0038E6DC;

void Clear_001EC910(int v)
{
    for (Node_001EC910* n = D_0038E6DC; n; n = n->m5C)
        if (n->m4 == v) n->m4 = 0;
}
