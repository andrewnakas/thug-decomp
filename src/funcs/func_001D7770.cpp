/* sym: __13Node_001D7770 = 0x001D7710 */
extern int D_00388A70;
extern "C" void* func_0010A638(int heap, unsigned int size, int, int);
extern "C" void* func_00331404(void* dst, const void* src, unsigned int n);

class Node_001D7770 {
public:
    Node_001D7770();
    ~Node_001D7770();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
    bool IsLeaf() const { return (m_type & 3) == 3; }
    unsigned char m_type;
    unsigned char m1;
    unsigned short m_count;
    unsigned int m_link;
};

extern "C" int func_001D78E8(Node_001D7770* t);
extern "C" int func_001D7958(Node_001D7770* t);
extern "C" unsigned short* func_001D79C0(Node_001D7770* t);

extern "C" Node_001D7770* func_001D7770(Node_001D7770* root)
{
    int numNodes = func_001D78E8(root);
    int numData = func_001D7958(root);
    if (numNodes > 0) {
    unsigned short* oldData = func_001D79C0(root);
    Node_001D7770* nodes = new Node_001D7770[numNodes];
    unsigned short* data = (unsigned short*)func_0010A638(D_00388A70, numData * 2, 1, 0);
    func_00331404(nodes, root, numNodes * 8);
    func_00331404(data, oldData, numData * 2);
    int dataDelta = (char*)data - (char*)oldData;
    int nodeDelta = (char*)nodes - (char*)root;
    for (int i = 0; i < numNodes; i++) {
        Node_001D7770* n = &nodes[i];
        if (!n->IsLeaf()) {
            n->m_link = ((n->m_link & ~3) + nodeDelta) | (n->m_link & 3);
        } else {
            n->m_link = n->m_link + dataDelta;
        }
    }
    return nodes;
    }
    return 0;
}
