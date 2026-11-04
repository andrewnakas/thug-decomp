union Node_0015FE60 {
    Node_0015FE60* m_child[16];
    float m_val[6];
};

extern "C" void func_0015FE60(Node_0015FE60* n, unsigned char* p, int level, unsigned char* box, float* acc)
{
    if (n == 0) return;
    int size = 1 << level;
    int d0 = p[0] - box[4];
    int d1 = p[1] - box[5];
    int d2 = p[2] - box[6];
    int d3 = p[3] - box[7];
    if (d0 >= 0 || d1 >= 0 || d2 >= 0 || d3 >= 0) return;
    int e0 = box[0] - p[0];
    int e1 = box[1] - p[1];
    int e2 = box[2] - p[2];
    int e3 = box[3] - p[3];
    if (e0 >= size || e1 >= size || e2 >= size || e3 >= size) return;
    size = -size;
    if (d0 <= size && d1 <= size && d2 <= size && d3 <= size
        && e0 <= 0 && e1 <= 0 && e2 <= 0 && e3 <= 0 && level == 0) {
        acc[0] += n->m_val[0];
        acc[1] += n->m_val[1];
        acc[2] += n->m_val[2];
        acc[3] += n->m_val[3];
        acc[4] += n->m_val[4];
        acc[5] += n->m_val[5];
        return;
    }
    level--;
    for (int i = 0; i < 16; i++) {
        unsigned char q[4];
        q[0] = p[0] + (((i >> 3) & 1) << level);
        q[1] = p[1] + (((i >> 2) & 1) << level);
        q[2] = p[2] + (((i >> 1) & 1) << level);
        q[3] = p[3] + ((i & 1) << level);
        func_0015FE60(n->m_child[i], q, level, box, acc);
    }
}
