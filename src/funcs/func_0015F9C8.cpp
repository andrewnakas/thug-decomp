extern "C" void* func_0015F938();
extern "C" void func_0015F8D8(void* p);
extern "C" void func_0015F900(void* p);

struct Node_0015F9C8 {
    Node_0015F9C8* m_child[16];
};

struct Tree_0015F9C8 {
    Node_0015F9C8* Fn(Node_0015F9C8* node, unsigned int key, int depth);
};

Node_0015F9C8* Tree_0015F9C8::Fn(Node_0015F9C8* node, unsigned int key, int depth)
{
    if (!depth)
        return node;
    if (!node->m_child[key & 0xF]) {
        Node_0015F9C8* p = (Node_0015F9C8*)func_0015F938();
        node->m_child[key & 0xF] = p;
        if (depth == 1)
            func_0015F8D8(p);
        else
            func_0015F900(p);
    }
    return Fn(node->m_child[key & 0xF], key >> 4, depth - 1);
}
