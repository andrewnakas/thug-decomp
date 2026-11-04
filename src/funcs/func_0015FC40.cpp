struct Rgba_0015FC40 {
    unsigned char r, g, b, a;
};

struct Box_0015FC40 {
    Rgba_0015FC40 min;
    Rgba_0015FC40 max;
};

struct Node_0015FC40 {
    union {
        Node_0015FC40* child[16];
        struct {
            char pad[0x18];
            unsigned char val;
        };
    };
};

extern "C" void func_0015FC40(Node_0015FC40* node, Rgba_0015FC40* o, int level, Box_0015FC40* box, int val)
{
    if (!node)
        return;
    int size = 1 << level;
    int d0 = o->r - box->max.r;
    int d1 = o->g - box->max.g;
    int d2 = o->b - box->max.b;
    int d3 = o->a - box->max.a;
    if (d0 >= 0 || d1 >= 0 || d2 >= 0 || d3 >= 0)
        return;
    int e0 = box->min.r - o->r;
    int e1 = box->min.g - o->g;
    int e2 = box->min.b - o->b;
    int e3 = box->min.a - o->a;
    if (e0 >= size || e1 >= size || e2 >= size || e3 >= size)
        return;
    int neg = -size;
    if (d0 <= neg && d1 <= neg && d2 <= neg && d3 <= neg && e0 <= 0 && e1 <= 0 && e2 <= 0 && e3 <= 0 && level == 0) {
        node->val = val;
        return;
    }
    level--;
    for (int i = 0; i < 16; i++) {
        Rgba_0015FC40 c;
        c.r = o->r + (((i >> 3) & 1) << level);
        c.g = o->g + (((i >> 2) & 1) << level);
        c.b = o->b + (((i >> 1) & 1) << level);
        c.a = o->a + ((i & 1) << level);
        func_0015FC40(node->child[i], &c, level, box, val);
    }
}
