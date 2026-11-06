struct Node_0012DDE8 {
    char pad[0x44];
    int m44;
    char pad48[0xC];
    Node_0012DDE8* m54;
    char pad58[8];
    Node_0012DDE8* m60;
    void Dec()
    {
        bool ok = m44 > 0;
        if (ok)
            m44--;
    }
};

struct C_0012DDE8 {
    char pad[0x4C];
    Node_0012DDE8* m4C;
    void Adjust(int up);
};

void C_0012DDE8::Adjust(int up)
{
    if (!m4C)
        return;
    Node_0012DDE8* stack[32];
    stack[0] = m4C;
    int count = 1;
    do {
        count--;
        Node_0012DDE8* n = stack[count];
        if (up == 1)
            n->m44++;
        else if (n->m44 > 0)
            n->Dec();
        if (n->m60) {
            stack[count] = n->m60;
            count++;
        }
        if (n->m54) {
            stack[count] = n->m54;
            count++;
        }
    } while (count);
}
