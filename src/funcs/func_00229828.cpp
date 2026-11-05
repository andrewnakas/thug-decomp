struct Node_00229828 {
    int m_data;
    Node_00229828* m_next;
};

extern Node_00229828* D_0038FB60;
extern Node_00229828* D_0038FB64;
extern "C" void* func_0010BDE0(int size);

void Init_00229828()
{
    D_0038FB60 = (Node_00229828*)func_0010BDE0(120000 * sizeof(Node_00229828));
    for (int i = 0; i < 119999; i++) {
        D_0038FB60[i].m_next = &D_0038FB60[i + 1];
    }
    D_0038FB60[119999].m_next = 0;
    D_0038FB64 = D_0038FB60;
}
