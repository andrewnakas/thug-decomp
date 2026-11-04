struct Node_00229998 {
    int m_val;
    Node_00229998* m_next;
};

struct Entry_00229998 {
    unsigned int m_key;
    Node_00229998* m_list;
};

extern Entry_00229998 D_003FD988[];
extern int D_0038FB68;

extern "C" Node_00229998* func_002298C0();
extern "C" int func_002297A8(unsigned int key);

void func_00229998(unsigned int key, int val)
{
    if (D_0038FB68 == 0) {
        Node_00229998* n = func_002298C0();
        n->m_val = val;
        n->m_next = 0;
        D_003FD988[0].m_key = key;
        D_003FD988[0].m_list = n;
        D_0038FB68++;
        return;
    }
    int i = func_002297A8(key);
    if (D_003FD988[i].m_key == key) {
        Node_00229998* n = func_002298C0();
        n->m_val = val;
        n->m_next = D_003FD988[i].m_list;
        D_003FD988[i].m_list = n;
        return;
    }
    i += (D_003FD988[i].m_key < key);
    for (int j = D_0038FB68; i < j; j--)
        D_003FD988[j] = D_003FD988[j - 1];
    Node_00229998* n = func_002298C0();
    n->m_val = val;
    n->m_next = 0;
    D_003FD988[i].m_key = key;
    D_003FD988[i].m_list = n;
    D_0038FB68++;
}
