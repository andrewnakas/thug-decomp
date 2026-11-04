struct Node_001D7FE0 {
    union {
        struct {
            unsigned int m_type : 2;
            int m_split : 30;
        } m_branch;
        struct {
            unsigned char m_flags;
            unsigned char m1;
            unsigned short m_count;
        } m_leaf;
    };
    union {
        unsigned short* m_indices;
        int m_children;
    };
};

struct Box_001D7FE0 {
    float m_min[4];
    float m_max[4];
};

extern int D_0039432C;
extern unsigned short D_004657E8[];

extern "C" Node_001D7FE0* func_001DA7D8(void* children);
extern "C" Node_001D7FE0* func_001DA820(void* children);

void func_001D7FE0(void* self, Node_001D7FE0* node, Box_001D7FE0* bbox)
{
    int axis = node->m_leaf.m_flags & 3;
    if (axis == 3) {
        unsigned short* dst = &D_004657E8[D_0039432C];
        unsigned short* src = node->m_indices;
        unsigned int count = node->m_leaf.m_count;
        for (unsigned int i = 0; i < count; i++) {
            *dst++ = *src++;
        }
        D_0039432C += count;
        return;
    }
    float split = (float)node->m_branch.m_split * 0.0625f;
    if (bbox->m_min[axis] < split) {
        func_001D7FE0(self, func_001DA7D8(&node->m_children), bbox);
    }
    if (split <= bbox->m_max[axis]) {
        func_001D7FE0(self, func_001DA820(&node->m_children), bbox);
    }
}
