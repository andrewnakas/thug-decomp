struct Node_001D7A60 {
    int axis : 2;
    int split : 30;
};

extern "C" Node_001D7A60* func_001DA7D8(Node_001D7A60* n);
extern "C" Node_001D7A60* func_001DA820(Node_001D7A60* n);

void func_001D7A60(Node_001D7A60* n, float* offset)
{
    int axis = *(unsigned char*)n & 3;
    if ((axis ^ 3) == 0) return;
    float* o = offset;
    o += axis;
    float v = ((float)n->split * (1.0f / 16.0f) + *o) * 16.0f;
    *(int*)n = ((int)v << 2) | axis;
    Node_001D7A60* c = n + 1;
    func_001D7A60(func_001DA7D8(c), offset);
    func_001D7A60(func_001DA820(c), offset);
}
