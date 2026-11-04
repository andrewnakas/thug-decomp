struct Node_001ABDE8 {
    unsigned char m0;
    unsigned char m_type;
    unsigned char m2;
    unsigned char m3;
    int m4;
    unsigned int m_value;
    Node_001ABDE8* m_next;
};

extern "C" unsigned int func_00203300(unsigned int v, int flags);

struct C_001ABDE8 {
    int m_pad[616];
    unsigned int m9A0;
    unsigned int m9A4;
    unsigned int m9A8;
    unsigned int Resolve(Node_001ABDE8* node, int n, unsigned int* out);
};

unsigned int C_001ABDE8::Resolve(Node_001ABDE8* node, int n, unsigned int* out)
{
    for (int i = 0; i < n; i++) {
        unsigned int v = node->m_value;
        switch (v) {
        case 0x9A7DC229:
            *out = m9A0;
            break;
        case 0x03749393:
            *out = m9A4;
            break;
        case 0x7473A305:
            *out = m9A8;
            break;
        default:
            *out = v;
            break;
        }
        node = node->m_next;
        out++;
    }
    if (node->m_type == 1) return node->m_value;
    return func_00203300(node->m_value, 0);
}
