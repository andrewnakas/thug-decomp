struct Vec_001D7D00 {
    float x, y, z, w;
};

struct Node_001D7D00 {
    union {
        struct {
            unsigned char m_axis : 2;
            int m_split : 30;
        } f;
        unsigned int m_word;
    } u;
    int m_children;
};

extern "C" void func_001D7A60(Node_001D7D00*, Vec_001D7D00*);
extern "C" Node_001D7D00* func_001DA7D8(int*);
extern "C" Node_001D7D00* func_001DA820(int*);

void func_001D7D00(Node_001D7D00* node, Vec_001D7D00* offset, float* scales, int top)
{
    if (top) {
        Vec_001D7D00 neg;
        neg.x = -offset->x;
        neg.y = -offset->y;
        neg.z = -offset->z;
        neg.w = -offset->w;
        func_001D7A60(node, &neg);
    }
    unsigned int axis = node->u.f.m_axis;
    bool leaf = axis == 3;
    if (!leaf) {
        float* s = scales;
        s += axis;
        float split = (float)node->u.f.m_split / 16.0f;
        node->u.m_word = ((int)(split * *s * 16.0f) << 2) | axis;
        func_001D7D00(func_001DA7D8(&node->m_children), offset, scales, 0);
        func_001D7D00(func_001DA820(&node->m_children), offset, scales, 0);
    }
    if (top)
        func_001D7A60(node, offset);
}
